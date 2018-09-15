#ifndef DATAMANAGEMENTLISTVIEW_H
#define DATAMANAGEMENTLISTVIEW_H
#include "QAbstractListModel"
#include "QMediaPlayer"
#include "QMediaPlaylist"
#include "QMediaMetaData"
#include "QString"
#include "QDir"
#include "QUrl"
#include "QDebug"
#include "QImage"



class dataManagementListView : public QAbstractListModel {
  Q_OBJECT
  Q_DISABLE_COPY(dataManagementListView)

private:
  //singleton
  static dataManagementListView* instance;

  //metaData
  QList<QString>mNameFile;
  QList<float>mDuration;
  QList<QString>mFormatFile;
  QList<QString>mCoverUrl;
  QImage mImageFolder;
  QList<QString>mTypeElement;

  //player
  QMediaPlayer *mPlayer;
  QMediaPlaylist *mPlayList;

  QFileInfoList mListFiles;
  QFileInfoList mListFolder; //I use two var because suffix bad work.

  //filters for file
  QStringList filters;



  enum Roles{
    nameComposition=Qt::UserRole+1,
    duration,
    cover,
    format,
    type
  };

  dataManagementListView(QObject *parent = Q_NULLPTR);
  virtual QHash<int, QByteArray> roleNames() const;
  virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
  virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
  virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

  void getMetaDataAndType(QFileInfoList &listFiles);
  void clearMetaDataAndType();


public:
  static dataManagementListView* getInstance(); 
  ~dataManagementListView();
    //for provider
  QUrl getMusic(int index);
  void setDuration(int index, float duration);
  bool checkIndex(int index);
  QImage getImageFolder();

private slots:
  void playListIndexChanged(int index);

public slots:
  bool setUrl(QString url);
  void play();
  void stop();
  void setIndexPlayList(int index);


signals:
  void endLoadData();
  void changedCurrentIndex(int indexPl);
};

#endif // DATAMANAGEMENTLISTVIEW_H
