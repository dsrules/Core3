/*
 *	server/zone/managers/player/PlayerManager.cpp generated by engine3 IDL compiler 0.60
 */

#include "PlayerManager.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/ZoneProcessServerImplementation.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/packets/MessageCallback.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/ZoneServer.h"

/*
 *	PlayerManagerStub
 */

PlayerManager::PlayerManager(ZoneServer* zoneServer, ZoneProcessServerImplementation* impl) : ManagedObject(DummyConstructorParameter::instance()) {
	_impl = new PlayerManagerImplementation(zoneServer, impl);
	_impl->_setStub(this);
}

PlayerManager::PlayerManager(DummyConstructorParameter* param) : ManagedObject(param) {
}

PlayerManager::~PlayerManager() {
}


TransactionalObject* PlayerManager::clone() {
	PlayerManager* objectCopy = new PlayerManager(DummyConstructorParameter::instance());
	objectCopy->_impl = new PlayerManagerImplementation(DummyConstructorParameter::instance());
	*(objectCopy->_impl) = *_impl;
	return (TransactionalObject*) objectCopy;
}


void PlayerManager::loadNameMap() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->loadNameMap();
}

bool PlayerManager::createPlayer(MessageCallback* callback) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((PlayerManagerImplementation*) _impl)->createPlayer(callback);
}

bool PlayerManager::checkPlayerName(MessageCallback* callback) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((PlayerManagerImplementation*) _impl)->checkPlayerName(callback);
}

bool PlayerManager::checkExistentNameInDatabase(const String& firstName) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addAsciiParameter(firstName);

		return method.executeWithBooleanReturn();
	} else
		return ((PlayerManagerImplementation*) _impl)->checkExistentNameInDatabase(firstName);
}

TangibleObject* PlayerManager::createHairObject(const String& hairObjectFile, const String& hairCustomization) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addAsciiParameter(hairObjectFile);
		method.addAsciiParameter(hairCustomization);

		return (TangibleObject*) method.executeWithObjectReturn();
	} else
		return ((PlayerManagerImplementation*) _impl)->createHairObject(hairObjectFile, hairCustomization);
}

bool PlayerManager::createAllPlayerObjects(PlayerCreature* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(player);

		return method.executeWithBooleanReturn();
	} else
		return ((PlayerManagerImplementation*) _impl)->createAllPlayerObjects(player);
}

void PlayerManager::createDefaultPlayerItems(PlayerCreature* player, const String& profession, const String& templateFile) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(player);
		method.addAsciiParameter(profession);
		method.addAsciiParameter(templateFile);

		method.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->createDefaultPlayerItems(player, profession, templateFile);
}

void PlayerManager::createTutorialBuilding(PlayerCreature* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->createTutorialBuilding(player);
}

void PlayerManager::createSkippedTutorialBuilding(PlayerCreature* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->createSkippedTutorialBuilding(player);
}

bool PlayerManager::existsName(const String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addAsciiParameter(name);

		return method.executeWithBooleanReturn();
	} else
		return ((PlayerManagerImplementation*) _impl)->existsName(name);
}

unsigned long long PlayerManager::getObjectID(const String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addAsciiParameter(name);

		return method.executeWithUnsignedLongReturn();
	} else
		return ((PlayerManagerImplementation*) _impl)->getObjectID(name);
}

PlayerCreature* PlayerManager::getPlayer(const String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addAsciiParameter(name);

		return (PlayerCreature*) method.executeWithObjectReturn();
	} else
		return ((PlayerManagerImplementation*) _impl)->getPlayer(name);
}

/*
 *	PlayerManagerImplementation
 */

PlayerManagerImplementation::PlayerManagerImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}

PlayerManagerImplementation::~PlayerManagerImplementation() {
	PlayerManagerImplementation::finalize();
}


void PlayerManagerImplementation::_initializeImplementation() {
	_setClassHelper(PlayerManagerHelper::instance());

	_serializationHelperMethod();
}

void PlayerManagerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (PlayerManager*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* PlayerManagerImplementation::_getStub() {
	return _this;
}

PlayerManagerImplementation::operator const PlayerManager*() {
	return _this;
}

void PlayerManagerImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void PlayerManagerImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void PlayerManagerImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void PlayerManagerImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void PlayerManagerImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void PlayerManagerImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void PlayerManagerImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void PlayerManagerImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("PlayerManager");

	addSerializableVariable("server", &server);
}

/*
 *	PlayerManagerAdapter
 */

PlayerManagerAdapter::PlayerManagerAdapter(PlayerManagerImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* PlayerManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		loadNameMap();
		break;
	case 7:
		finalize();
		break;
	case 8:
		resp->insertBoolean(checkExistentNameInDatabase(inv->getAsciiParameter(_param0_checkExistentNameInDatabase__String_)));
		break;
	case 9:
		resp->insertLong(createHairObject(inv->getAsciiParameter(_param0_createHairObject__String_String_), inv->getAsciiParameter(_param1_createHairObject__String_String_))->_getObjectID());
		break;
	case 10:
		resp->insertBoolean(createAllPlayerObjects((PlayerCreature*) inv->getObjectParameter()));
		break;
	case 11:
		createDefaultPlayerItems((PlayerCreature*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_createDefaultPlayerItems__PlayerCreature_String_String_), inv->getAsciiParameter(_param2_createDefaultPlayerItems__PlayerCreature_String_String_));
		break;
	case 12:
		createTutorialBuilding((PlayerCreature*) inv->getObjectParameter());
		break;
	case 13:
		createSkippedTutorialBuilding((PlayerCreature*) inv->getObjectParameter());
		break;
	case 14:
		resp->insertBoolean(existsName(inv->getAsciiParameter(_param0_existsName__String_)));
		break;
	case 15:
		resp->insertLong(getObjectID(inv->getAsciiParameter(_param0_getObjectID__String_)));
		break;
	case 16:
		resp->insertLong(getPlayer(inv->getAsciiParameter(_param0_getPlayer__String_))->_getObjectID());
		break;
	default:
		return NULL;
	}

	return resp;
}

void PlayerManagerAdapter::loadNameMap() {
	((PlayerManagerImplementation*) impl)->loadNameMap();
}

void PlayerManagerAdapter::finalize() {
	((PlayerManagerImplementation*) impl)->finalize();
}

bool PlayerManagerAdapter::checkExistentNameInDatabase(const String& firstName) {
	return ((PlayerManagerImplementation*) impl)->checkExistentNameInDatabase(firstName);
}

TangibleObject* PlayerManagerAdapter::createHairObject(const String& hairObjectFile, const String& hairCustomization) {
	return ((PlayerManagerImplementation*) impl)->createHairObject(hairObjectFile, hairCustomization);
}

bool PlayerManagerAdapter::createAllPlayerObjects(PlayerCreature* player) {
	return ((PlayerManagerImplementation*) impl)->createAllPlayerObjects(player);
}

void PlayerManagerAdapter::createDefaultPlayerItems(PlayerCreature* player, const String& profession, const String& templateFile) {
	((PlayerManagerImplementation*) impl)->createDefaultPlayerItems(player, profession, templateFile);
}

void PlayerManagerAdapter::createTutorialBuilding(PlayerCreature* player) {
	((PlayerManagerImplementation*) impl)->createTutorialBuilding(player);
}

void PlayerManagerAdapter::createSkippedTutorialBuilding(PlayerCreature* player) {
	((PlayerManagerImplementation*) impl)->createSkippedTutorialBuilding(player);
}

bool PlayerManagerAdapter::existsName(const String& name) {
	return ((PlayerManagerImplementation*) impl)->existsName(name);
}

unsigned long long PlayerManagerAdapter::getObjectID(const String& name) {
	return ((PlayerManagerImplementation*) impl)->getObjectID(name);
}

PlayerCreature* PlayerManagerAdapter::getPlayer(const String& name) {
	return ((PlayerManagerImplementation*) impl)->getPlayer(name);
}

/*
 *	PlayerManagerHelper
 */

PlayerManagerHelper* PlayerManagerHelper::staticInitializer = PlayerManagerHelper::instance();

PlayerManagerHelper::PlayerManagerHelper() {
	className = "PlayerManager";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void PlayerManagerHelper::finalizeHelper() {
	PlayerManagerHelper::finalize();
}

DistributedObject* PlayerManagerHelper::instantiateObject() {
	return new PlayerManager(DummyConstructorParameter::instance());
}

DistributedObjectServant* PlayerManagerHelper::instantiateServant() {
	return new PlayerManagerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* PlayerManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new PlayerManagerAdapter((PlayerManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

