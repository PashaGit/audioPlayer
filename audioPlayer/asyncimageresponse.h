#ifndef ASYNCIMAGERESPONSE_H
#define ASYNCIMAGERESPONSE_H
#include "datamanagementlistview.h"
#include <qquickimageprovider.h>
#include <QThreadPool>
#include <QEventLoop>



class asyncImageResponse : public QQuickImageResponse, public QRunnable
{
  friend class asyncImageProvider;
private:
  QString mId;
  QImage mImage;
  int mIndex;
  QMediaPlayer *player;

  QQuickTextureFactory *textureFactory() const override;
  asyncImageResponse(const QString &id, const QSize &requestedSize);
  void run();
  ~asyncImageResponse();
};

#endif // ASYNCIMAGERESPONSE_H
