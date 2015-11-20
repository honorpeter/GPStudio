#ifndef FLOWMANAGER_H
#define FLOWMANAGER_H

#include "gpstudio_lib_common.h"

#include "model/node.h"
#include "flowconnection.h"

#include <QMap>

class GPSTUDIO_LIB_EXPORT FlowManager
{
public:
    FlowManager(Node *node);

    Node *node() const;
    void setNode(Node *node);

    void addFlowConnection(FlowConnection *flowConnection);
private:
    Node *_node;
    QMap<int, FlowConnection* > _flowConnectionsID;
};

#endif // FLOWMANAGER_H