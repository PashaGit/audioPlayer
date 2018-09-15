#ifndef ASYNCIMAGEPROVIDER_H
#define ASYNCIMAGEPROVIDER_H
#include "asyncimageresponse.h"


class asyncImageProvider : public QQuickAsyncImageProvider
{
private:
  QThreadPool pool;
public:
  asyncImageProvider();
  virtual QQuickImageResponse *requestImageResponse(const QString &id, const QSize &requestedSize);
};

#endif // ASYNCIMAGEPROVIDER_H
