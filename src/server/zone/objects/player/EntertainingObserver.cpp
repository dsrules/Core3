/*
 *	server/zone/objects/player/EntertainingObserver.cpp generated by engine3 IDL compiler 0.60
 */

#include "EntertainingObserver.h"

#include "server/zone/objects/creature/CreatureObject.h"


// Imported class dependencies

#include "engine/core/ManagedObject.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "engine/service/proto/BaseMessage.h"

#include "engine/util/Observable.h"

#include "engine/util/Observer.h"

#include "engine/util/ObserverEventMap.h"

#include "server/chat/StringIdChatParameter.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/SpeedMultiplierModChanges.h"

#include "server/zone/objects/creature/buffs/Buff.h"

#include "server/zone/objects/creature/buffs/BuffList.h"

#include "server/zone/objects/creature/damageovertime/DamageOverTimeList.h"

#include "server/zone/objects/creature/professions/SkillBox.h"

#include "server/zone/objects/creature/variables/CommandQueueAction.h"

#include "server/zone/objects/creature/variables/CooldownTimerMap.h"

#include "server/zone/objects/creature/variables/SkillBoxList.h"

#include "server/zone/objects/group/GroupList.h"

#include "server/zone/objects/group/GroupObject.h"

#include "server/zone/objects/guild/GuildObject.h"

#include "server/zone/objects/intangible/ControlDevice.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "system/io/ObjectInputStream.h"

#include "system/io/ObjectOutputStream.h"

#include "system/lang/Time.h"

#include "system/util/Vector.h"

/*
 *	EntertainingObserverStub
 */

enum {RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_ = 6};

EntertainingObserver::EntertainingObserver() : Observer(DummyConstructorParameter::instance()) {
	EntertainingObserverImplementation* _implementation = new EntertainingObserverImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

EntertainingObserver::EntertainingObserver(DummyConstructorParameter* param) : Observer(param) {
}

EntertainingObserver::~EntertainingObserver() {
}


int EntertainingObserver::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	EntertainingObserverImplementation* _implementation = (EntertainingObserverImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_);
		method.addUnsignedIntParameter(eventType);
		method.addObjectParameter(observable);
		method.addObjectParameter(arg1);
		method.addSignedLongParameter(arg2);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->notifyObserverEvent(eventType, observable, arg1, arg2);
}

DistributedObjectServant* EntertainingObserver::_getImplementation() {

	_updated = true;
	return _impl;
}

void EntertainingObserver::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	EntertainingObserverImplementation
 */

EntertainingObserverImplementation::EntertainingObserverImplementation(DummyConstructorParameter* param) : ObserverImplementation(param) {
	_initializeImplementation();
}


EntertainingObserverImplementation::~EntertainingObserverImplementation() {
}


void EntertainingObserverImplementation::finalize() {
}

void EntertainingObserverImplementation::_initializeImplementation() {
	_setClassHelper(EntertainingObserverHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void EntertainingObserverImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (EntertainingObserver*) stub;
	ObserverImplementation::_setStub(stub);
}

DistributedObjectStub* EntertainingObserverImplementation::_getStub() {
	return _this;
}

EntertainingObserverImplementation::operator const EntertainingObserver*() {
	return _this;
}

void EntertainingObserverImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void EntertainingObserverImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void EntertainingObserverImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void EntertainingObserverImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void EntertainingObserverImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void EntertainingObserverImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void EntertainingObserverImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void EntertainingObserverImplementation::_serializationHelperMethod() {
	ObserverImplementation::_serializationHelperMethod();

	_setClassName("EntertainingObserver");

}

void EntertainingObserverImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(EntertainingObserverImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool EntertainingObserverImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ObserverImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void EntertainingObserverImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = EntertainingObserverImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int EntertainingObserverImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + ObserverImplementation::writeObjectMembers(stream);
}

EntertainingObserverImplementation::EntertainingObserverImplementation() {
	_initializeImplementation();
	// server/zone/objects/player/EntertainingObserver.idl():  		;
}

int EntertainingObserverImplementation::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	// server/zone/objects/player/EntertainingObserver.idl():  		CreatureObject 
	if (eventType != ObserverEventType::POSTURECHANGED){
	// server/zone/objects/player/EntertainingObserver.idl():  			return 1;
	return 1;
}
	// server/zone/objects/player/EntertainingObserver.idl():  		CreatureObject creature = (CreatureObject) observable;
	CreatureObject* creature = (CreatureObject*) observable;
	// server/zone/objects/player/EntertainingObserver.idl():  		creature.stopEntertaining();
	creature->stopEntertaining();
	// server/zone/objects/player/EntertainingObserver.idl():  		return 1;
	return 1;
}

/*
 *	EntertainingObserverAdapter
 */

EntertainingObserverAdapter::EntertainingObserverAdapter(EntertainingObserverImplementation* obj) : ObserverAdapter(obj) {
}

Packet* EntertainingObserverAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_:
		resp->insertSignedInt(notifyObserverEvent(inv->getUnsignedIntParameter(), (Observable*) inv->getObjectParameter(), (ManagedObject*) inv->getObjectParameter(), inv->getSignedLongParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

int EntertainingObserverAdapter::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return ((EntertainingObserverImplementation*) impl)->notifyObserverEvent(eventType, observable, arg1, arg2);
}

/*
 *	EntertainingObserverHelper
 */

EntertainingObserverHelper* EntertainingObserverHelper::staticInitializer = EntertainingObserverHelper::instance();

EntertainingObserverHelper::EntertainingObserverHelper() {
	className = "EntertainingObserver";

	Core::getObjectBroker()->registerClass(className, this);
}

void EntertainingObserverHelper::finalizeHelper() {
	EntertainingObserverHelper::finalize();
}

DistributedObject* EntertainingObserverHelper::instantiateObject() {
	return new EntertainingObserver(DummyConstructorParameter::instance());
}

DistributedObjectServant* EntertainingObserverHelper::instantiateServant() {
	return new EntertainingObserverImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* EntertainingObserverHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new EntertainingObserverAdapter((EntertainingObserverImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

