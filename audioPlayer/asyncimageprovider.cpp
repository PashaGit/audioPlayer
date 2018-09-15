#include "asyncimageprovider.h"

asyncImageProvider::asyncImageProvider(){}

QQuickImageResponse* asyncImageProvider::requestImageResponse(const QString &id, const QSize &requestedSize){
  asyncImageResponse* response=new asyncImageResponse(id, requestedSize);
  pool.start(response);
  return response;
}
