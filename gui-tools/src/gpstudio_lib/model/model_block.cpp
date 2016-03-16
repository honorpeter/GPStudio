#include "model_block.h"

#include <QDebug>
#include <QStringList>

#include "model_io.h"
#include "model_iocom.h"
#include "model_process.h"
#include "model_piblock.h"
#include "model_fiblock.h"
#include "model_ciblock.h"

ModelBlock::ModelBlock()
{
}

ModelBlock::~ModelBlock()
{
    for(int i=0; i<_files.size(); i++) delete _files[i];
    for(int i=0; i<_params.size(); i++) delete _params[i];
    for(int i=0; i<_properties.size(); i++) delete _properties[i];
    for(int i=0; i<_flows.size(); i++) delete _flows[i];
    for(int i=0; i<_clocks.size(); i++) delete _clocks[i];
    for(int i=0; i<_ports.size(); i++) delete _ports[i];
    for(int i=0; i<_pins.size(); i++) delete _pins[i];
    for(int i=0; i<_resets.size(); i++) delete _resets[i];
}

const QString &ModelBlock::name() const
{
    return _name;
}

void ModelBlock::setName(const QString &name)
{
    _name = name;
}

bool ModelBlock::inLib() const
{
    return _inLib;
}

void ModelBlock::setInLib(bool inLib)
{
    _inLib = inLib;
}

const QString &ModelBlock::driver() const
{
    return _driver;
}

void ModelBlock::setDriver(const QString &driver)
{
    _driver = driver;
}

const QString &ModelBlock::categ() const
{
    return _categ;
}

void ModelBlock::setCateg(const QString &categ)
{
    _categ = categ;
}

qint32 ModelBlock::addrAbs() const
{
    return _addrAbs;
}

void ModelBlock::setAddrAbs(const qint32 &value)
{
    _addrAbs = value;
}

quint8 ModelBlock::sizeAddrRel() const
{
    return _sizeAddrRel;
}

void ModelBlock::setSizeAddrRel(const quint8 &value)
{
    _sizeAddrRel = value;
}

quint8 ModelBlock::masterCount() const
{
    return _masterCount;
}

void ModelBlock::setMasterCount(const quint8 &value)
{
    _masterCount = value;
}

int ModelBlock::xPos() const
{
    return _xPos;
}

void ModelBlock::setXPos(int value)
{
    _xPos = value;
}

int ModelBlock::yPos() const
{
    return _yPos;
}

void ModelBlock::setYPos(int value)
{
    _yPos = value;
}

const QString &ModelBlock::description() const
{
    return _description;
}

void ModelBlock::setDescription(const QString &description)
{
    _description = description;
}

QString ModelBlock::type() const
{
    return "block";
}

QList<ModelFile *> &ModelBlock::files()
{
    return _files;
}

const QList<ModelFile *> &ModelBlock::files() const
{
    return _files;
}

void ModelBlock::addFile(ModelFile *file)
{
    file->setParent(this);
    _files.append(file);
}

void ModelBlock::addFiles(const QList<ModelFile *> &files)
{
    foreach (ModelFile *file, files)
    {
        addFile(file);
    }
}

ModelFile *ModelBlock::getFile(const QString &name) const
{
    for(int i=0; i<this->files().size(); i++)
    {
        ModelFile *file = this->files().at(i);
        if(file->name()==name) return file;
    }
    return NULL;
}

QList<ModelParam *> &ModelBlock::params()
{
    return _params;
}

const QList<ModelParam *> &ModelBlock::params() const
{
    return _params;
}

void ModelBlock::addParam(ModelParam *param)
{
    param->setParent(this);
    _params.append(param);
}

void ModelBlock::addParams(const QList<ModelParam *> &params)
{
    foreach (ModelParam *param, params)
    {
        addParam(param);
    }
}

ModelParam *ModelBlock::getParam(const QString &name) const
{
    for(int i=0; i<this->params().size(); i++)
    {
        ModelParam *param = this->params().at(i);
        if(param->name()==name) return param;
    }
    return NULL;
}

QList<ModelProperty *> &ModelBlock::properties()
{
    return _properties;
}

const QList<ModelProperty *> &ModelBlock::properties() const
{
    return _properties;
}

void ModelBlock::addProperty(ModelProperty *property)
{
    property->setParent(this);
    _properties.append(property);
}

void ModelBlock::addProperties(const QList<ModelProperty *> &properties)
{
    foreach (ModelProperty *property, properties)
    {
        addProperty(property);
    }
}

ModelProperty *ModelBlock::getBlockProperty(const QString &name) const
{
    for(int i=0; i<this->properties().size(); i++)
    {
        ModelProperty *blockProperty = this->properties().at(i);
        if(blockProperty->name()==name) return blockProperty;
    }
    return NULL;
}

QList<ModelFlow *> &ModelBlock::flows()
{
    return _flows;
}

const QList<ModelFlow *> &ModelBlock::flows() const
{
    return _flows;
}

void ModelBlock::addFlow(ModelFlow *flow)
{
    flow->setParent(this);
    _flows.append(flow);
}

void ModelBlock::addFlows(const QList<ModelFlow *> &flows)
{
    foreach (ModelFlow *flow, flows)
    {
        addFlow(flow);
    }
}

ModelFlow *ModelBlock::getFlow(const QString &name) const
{
    for(int i=0; i<this->flows().size(); i++)
    {
        ModelFlow *flow = this->flows().at(i);
        if(flow->name()==name) return flow;
    }
    return NULL;
}

QList<ModelClock *> &ModelBlock::clocks()
{
    return _clocks;
}

const QList<ModelClock *> &ModelBlock::clocks() const
{
    return _clocks;
}

void ModelBlock::addClock(ModelClock *clock)
{
    clock->setParent(this);
    _clocks.append(clock);
}

void ModelBlock::addClocks(const QList<ModelClock *> &clocks)
{
    foreach (ModelClock *clock, clocks)
    {
        addClock(clock);
    }
}

ModelClock *ModelBlock::getClock(const QString &name) const
{
    for(int i=0; i<this->clocks().size(); i++)
    {
        ModelClock *clock = this->clocks().at(i);
        if(clock->name()==name) return clock;
    }
    return NULL;
}

QList<ModelPort *> &ModelBlock::ports()
{
    return _ports;
}

const QList<ModelPort *> &ModelBlock::ports() const
{
    return _ports;
}

void ModelBlock::addPort(ModelPort *port)
{
    port->setParent(this);
    _ports.append(port);
}

void ModelBlock::addPorts(const QList<ModelPort *> &ports)
{
    foreach (ModelPort *port, ports)
    {
        addPort(port);
    }
}

ModelPort *ModelBlock::getPort(const QString &name) const
{
    for(int i=0; i<this->ports().size(); i++)
    {
        ModelPort *port = this->ports().at(i);
        if(port->name()==name) return port;
    }
    return NULL;
}

QList<ModelPin *> &ModelBlock::pins()
{
    return _pins;
}

const QList<ModelPin *> &ModelBlock::pins() const
{
    return _pins;
}

void ModelBlock::addPin(ModelPin *pin)
{
    pin->setParent(this);
    _pins.append(pin);
}

void ModelBlock::addPins(const QList<ModelPin *> &pins)
{
    foreach (ModelPin *pin, pins)
    {
        addPin(pin);
    }
}

ModelPin *ModelBlock::getPin(const QString &name) const
{
    for(int i=0; i<this->pins().size(); i++)
    {
        ModelPin *pin = this->pins().at(i);
        if(pin->name()==name) return pin;
    }
    return NULL;
}

QList<ModelReset *> &ModelBlock::resets()
{
    return _resets;
}

const QList<ModelReset *> &ModelBlock::resets() const
{
    return _resets;
}

void ModelBlock::addReset(ModelReset *reset)
{
    reset->setParent(this);
    _resets.append(reset);
}

void ModelBlock::addResets(const QList<ModelReset *> &resets)
{
    foreach (ModelReset *reset, resets)
    {
        addReset(reset);
    }
}

ModelReset *ModelBlock::getReset(const QString &name) const
{
    for(int i=0; i<this->resets().size(); i++)
    {
        ModelReset *reset = this->resets().at(i);
        if(reset->name()==name) return reset;
    }
    return NULL;
}

ModelBlock *ModelBlock::fromNodeGenerated(const QDomElement &domElement, ModelBlock *block)
{
    if(block==NULL) block = new ModelBlock();

    bool ok=false;

    block->setName(domElement.attribute("name","no_name"));

    block->setInLib((domElement.attribute("in_lib","")=="1" || domElement.attribute("in_lib","")=="true"));

    block->setDriver(domElement.attribute("driver",""));
    block->setCateg(domElement.attribute("categ",""));

    int xPos = domElement.attribute("x_pos","-1").toInt(&ok);
    if(ok) block->setXPos(xPos); else block->setXPos(-1);

    int yPos = domElement.attribute("y_pos","-1").toInt(&ok);
    if(ok) block->setYPos(yPos); else block->setYPos(-1);

    int addrAbs = domElement.attribute("addr_abs","-1").toInt(&ok);
    if(ok) block->setAddrAbs(addrAbs); else block->setAddrAbs(-1);

    int sizeAddrRel = domElement.attribute("pi_size_addr_rel","0").toInt(&ok);
    if(ok && sizeAddrRel>=0) block->setSizeAddrRel(sizeAddrRel); else block->setSizeAddrRel(0);

    int masterCount = domElement.attribute("master_count","0").toInt(&ok);
    if(ok && masterCount>=0) block->setMasterCount(masterCount); else block->setMasterCount(0);

    block->setDescription(domElement.attribute("desc",""));

    QDomNode n = domElement.firstChild();
    while(!n.isNull())
    {
        QDomElement e = n.toElement();
        if(!e.isNull())
        {
            if(e.tagName()=="files") block->addFiles(ModelFile::listFromNodeGenerated(e));
            if(e.tagName()=="params") block->addParams(ModelParam::listFromNodeGenerated(e));
            if(e.tagName()=="properties") block->addProperties(ModelProperty::listFromNodeGenerated(e));
            if(e.tagName()=="flows") block->addFlows(ModelFlow::listFromNodeGenerated(e));
            if(e.tagName()=="clocks") block->addClocks(ModelClock::listFromNodeGenerated(e));
            if(e.tagName()=="resets") block->addResets(ModelReset::listFromNodeGenerated(e));
        }
        n = n.nextSibling();
    }

    return block;
}

QList<ModelBlock *> ModelBlock::listFromNodeGenerated(const QDomElement &domElement)
{
    QDomNode n = domElement.firstChild();
    QList<ModelBlock *> list;
    while(!n.isNull())
    {
        QDomElement e = n.toElement();
        if(!e.isNull())
        {
            ModelBlock *block=NULL;
            QString typeBlock = e.attribute("type");
            if(e.tagName()=="block")
            {
                if(typeBlock=="process") block = ModelProcess::fromNodeGenerated(e);
                if(typeBlock=="io") block = ModelIO::fromNodeGenerated(e);
                if(typeBlock=="iocom") block = ModelIOCom::fromNodeGenerated(e);
                if(typeBlock=="pi") block = ModelPIBlock::fromNodeGenerated(e);
                if(typeBlock=="fi") block = ModelFIBlock::fromNodeGenerated(e);
                if(typeBlock=="ci") block = ModelCIBlock::fromNodeGenerated(e);
                if(block==NULL) block = ModelBlock::fromNodeGenerated(e);

                list.append(block);
            }
        }
        n = n.nextSibling();
    }
    return list;
}