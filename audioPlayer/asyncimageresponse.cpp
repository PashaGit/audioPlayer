#include "asyncimageresponse.h"

asyncImageResponse::asyncImageResponse(const QString &id, const QSize &requestedSize)
  : mId(id), mImage(QImage("Null")){
  setAutoDelete(false);
  player=new QMediaPlayer(this);
  dataManagementListView::getInstance()->deleteServiceNumbers(mId);
}

QQuickTextureFactory* asyncImageResponse::textureFactory() const{
  return QQuickTextureFactory::textureFactoryForImage(mImage);
}

void asyncImageResponse::run(){
  //check QImage in Qlist
  if(mId=="error"){
    // emit finished();
      return;
    }
  int index=mId.toInt();
  if(!dataManagementListView::getInstance()->checkIndex(index)){
      mImage=dataManagementListView::getInstance()->getImageFolder();
      emit finished();
    } else {
      //best use another library for the operation, but I want to use only qt at the moment.
      qDebug() << dataManagementListView::getInstance()->getMusic(index);
      player->setMedia(dataManagementListView::getInstance()->getMusic(index));
      QThread::msleep(200);
      //When data are available;
      if(player->isMetaDataAvailable()){
          dataManagementListView::getInstance()->setDuration(index, player->metaData(QMediaMetaData::Duration).toFloat()); //I need an another plan.
          mImage=player->metaData(QMediaMetaData::ThumbnailImage).value<QImage>();
        }
      emit finished();
    }
}


asyncImageResponse::~asyncImageResponse(){
  delete player;
}
