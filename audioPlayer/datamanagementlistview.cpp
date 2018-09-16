#include "datamanagementlistview.h"

dataManagementListView* dataManagementListView::instance=nullptr;

dataManagementListView* dataManagementListView::getInstance(){
  if(instance==nullptr){
      instance=new dataManagementListView();
    }
  return instance;
}

dataManagementListView::dataManagementListView(QObject *parent)
  : mPlayer(nullptr), mPlayList(nullptr), filters(""),mImageFolder("://resources/folderIcon.png"){
  mPlayer= new QMediaPlayer(this);
  mPlayList = new QMediaPlaylist(mPlayer);
  mPlayer->setPlaylist(mPlayList);
  filters << "*.mp3";
  QObject::connect(mPlayList, SIGNAL(currentIndexChanged(int)), this, SLOT(playListIndexChanged(int)));
}

dataManagementListView::~dataManagementListView(){
  qDebug() << "dataMan";
  delete mPlayList;
  delete mPlayer;
}


QHash<int, QByteArray> dataManagementListView::roleNames() const {
  QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
  roles[nameComposition] = "nameComposition";
  roles[duration] = "durationComposition";
  roles[cover]="coverAudio";
  roles[format]= "formatFile";
  roles[type]= "typeData";
  return roles;
}

QVariant dataManagementListView::data(const QModelIndex &index, int role) const {
  if(!index.isValid())return QVariant();
  switch(role){
    case nameComposition:{ return mNameFile.at(index.row()); }
    case duration: { return mDuration.at(index.row()); }
    case cover: { return mCoverUrl.at(index.row());  }
    case format: { return mFormatFile.at(index.row()); }
    case type: { return mTypeElement.at(index.row()); }
    default: QVariant();
    }
  return QVariant();
}

int dataManagementListView::columnCount(const QModelIndex &parent) const { return 1; }

int dataManagementListView::rowCount(const QModelIndex &parent)const {
  if(parent.isValid()) return 0;
  return mNameFile.count();
}

bool dataManagementListView::setUrl(QString url){
  clearMetaDataAndType();
  QDir dir(url);
  dir.setFilter(QDir::Files | QDir::AllDirs);
  dir.setNameFilters(filters);
  dir.setSorting(QDir::Name | QDir::Type);
  mListFiles=dir.entryInfoList(QDir::Files);
  mListFolder=dir.entryInfoList(QDir::AllDirs);

  //here is mistake when you delete the file:///
  for(int i=0; i<mListFiles.size(); ++i)mPlayList->addMedia(QUrl("file:///"+mListFiles.at(i).filePath()));
  getMetaDataAndType(mListFiles);

  return true;
}

void dataManagementListView::getMetaDataAndType(QFileInfoList &listFiles){
  beginResetModel();
  for(int i=0; i<mListFolder.count(); ++i){
      mNameFile.append(mListFolder.at(i).fileName());
      mDuration.append(0);
      mCoverUrl.append(QString("image://loadImage/").append(QString::number(i)));
      mFormatFile.append("");
      mTypeElement.append("folder");
    }
  for(int i=0; i<mListFiles.count(); ++i){
      //load metaInformation without duration and cover;
      mNameFile.append(mListFiles.at(i).fileName());
      mDuration.append(0);
      mCoverUrl.append(QString("image://loadImage/").append(QString::number(i+mListFolder.count())));
      mFormatFile.append("mp3");
      mTypeElement.append("file");
    }
  endResetModel();
  mPlayList->setCurrentIndex(0);
  emit endLoadData();
  emit reloadImage();
}

void dataManagementListView::clearMetaDataAndType(){
  mListFiles.clear();
  mListFolder.clear();
  mNameFile.clear();
  mDuration.clear();
  mCoverUrl.clear();
  mFormatFile.clear();
  mTypeElement.clear();
  mPlayList->clear();
}



QUrl dataManagementListView::getMusic(int index){
  return QUrl("file:///"+mListFiles.at(index-mListFolder.count()).filePath());
}



void dataManagementListView::setDuration(int index, float duration){
  QModelIndex index1= createIndex(index, index);
  mDuration[index]=((duration/1000)/60);
  emit dataChanged(index1,  index1);
}

QImage dataManagementListView::getImageFolder(){
  return mImageFolder;
}



bool dataManagementListView::checkIndex(int index){
  if(index<mListFolder.count())return false;
  else return true;
}

void dataManagementListView::play(){
  mPlayer->play();
}

void dataManagementListView::stop(){
  mPlayer->stop();
}

void dataManagementListView::playListIndexChanged(int index){
  emit changedCurrentIndex(index+mListFolder.count());
}

void dataManagementListView::setIndexPlayList(int index){
  int indexReal=index-mListFolder.count();
  if(indexReal>=0)mPlayList->setCurrentIndex(indexReal);
}

void dataManagementListView::deleteServiceNumbers(QString &data){
  if(data.indexOf(";")>0)data.remove(data.indexOf(";"), data.size()-1);
}
