/*
 *	server/zone/objects/player/PlayerObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "PlayerObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/commands/QueueCommand.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/objects/waypoint/WaypointObject.h"

/*
 *	PlayerObjectStub
 */

PlayerObject::PlayerObject() : IntangibleObject(DummyConstructorParameter::instance()) {
	_impl = new PlayerObjectImplementation();
	_impl->_setStub(this);
}

PlayerObject::PlayerObject(DummyConstructorParameter* param) : IntangibleObject(param) {
}

PlayerObject::~PlayerObject() {
}


TransactionalObject* PlayerObject::clone() {
	PlayerObject* objectCopy = new PlayerObject(DummyConstructorParameter::instance());
	objectCopy->_impl = new PlayerObjectImplementation(DummyConstructorParameter::instance());
	*(objectCopy->_impl) = *_impl;
	return (TransactionalObject*) objectCopy;
}


void PlayerObject::loadTemplateData(LuaObject* templateData) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((PlayerObjectImplementation*) _impl)->loadTemplateData(templateData);
}

void PlayerObject::initializeTransientMembers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->initializeTransientMembers();
}

void PlayerObject::sendBaselinesTo(SceneObject* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->sendBaselinesTo(player);
}

void PlayerObject::sendMessage(BasePacket* msg) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(msg);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->sendMessage(msg);
}

void PlayerObject::addExperience(const String& xpType, int xp, bool notifyClient) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addAsciiParameter(xpType);
		method.addSignedIntParameter(xp);
		method.addBooleanParameter(notifyClient);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->addExperience(xpType, xp, notifyClient);
}

void PlayerObject::removeExperience(const String& xpType, bool notifyClient) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addAsciiParameter(xpType);
		method.addBooleanParameter(notifyClient);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->removeExperience(xpType, notifyClient);
}

void PlayerObject::addWaypoint(WaypointObject* waypoint, bool notifyClient) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((PlayerObjectImplementation*) _impl)->addWaypoint(waypoint, notifyClient);
}

void PlayerObject::addWaypoint(const String& planet, float positionX, float positionY, bool notifyClient) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addAsciiParameter(planet);
		method.addFloatParameter(positionX);
		method.addFloatParameter(positionY);
		method.addBooleanParameter(notifyClient);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->addWaypoint(planet, positionX, positionY, notifyClient);
}

void PlayerObject::removeWaypoint(unsigned long long waypointID, bool notifyClient) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addUnsignedLongParameter(waypointID);
		method.addBooleanParameter(notifyClient);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->removeWaypoint(waypointID, notifyClient);
}

void PlayerObject::addSkills(Vector<QueueCommand*>& skills, bool notifyClient) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((PlayerObjectImplementation*) _impl)->addSkills(skills, notifyClient);
}

void PlayerObject::addSkills(Vector<Certification*>& skills, bool notifyClient) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((PlayerObjectImplementation*) _impl)->addSkills(skills, notifyClient);
}

void PlayerObject::removeSkills(Vector<QueueCommand*>& skills, bool notifyClient) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((PlayerObjectImplementation*) _impl)->removeSkills(skills, notifyClient);
}

void PlayerObject::removeSkills(Vector<Certification*>& skills, bool notifyClient) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((PlayerObjectImplementation*) _impl)->removeSkills(skills, notifyClient);
}

void PlayerObject::setLanguageID(byte language, bool notifyClient) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addByteParameter(language);
		method.addBooleanParameter(notifyClient);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->setLanguageID(language, notifyClient);
}

void PlayerObject::addFriend(const String& name, bool notifyClient) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addAsciiParameter(name);
		method.addBooleanParameter(notifyClient);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->addFriend(name, notifyClient);
}

void PlayerObject::removeFriend(const String& name, bool notifyClient) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addAsciiParameter(name);
		method.addBooleanParameter(notifyClient);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->removeFriend(name, notifyClient);
}

void PlayerObject::addIgnore(const String& name, bool notifyClient) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addAsciiParameter(name);
		method.addBooleanParameter(notifyClient);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->addIgnore(name, notifyClient);
}

void PlayerObject::removeIgnore(const String& name, bool notifyClient) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);
		method.addAsciiParameter(name);
		method.addBooleanParameter(notifyClient);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->removeIgnore(name, notifyClient);
}

void PlayerObject::notifyOnline() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->notifyOnline();
}

void PlayerObject::notifyOffline() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->notifyOffline();
}

bool PlayerObject::hasFriend(const String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);
		method.addAsciiParameter(name);

		return method.executeWithBooleanReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->hasFriend(name);
}

bool PlayerObject::isIgnoring(const String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);
		method.addAsciiParameter(name);

		return method.executeWithBooleanReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->isIgnoring(name);
}

void PlayerObject::addReverseFriend(const String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);
		method.addAsciiParameter(name);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->addReverseFriend(name);
}

void PlayerObject::removeReverseFriend(const String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);
		method.addAsciiParameter(name);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->removeReverseFriend(name);
}

void PlayerObject::sendFriendLists() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->sendFriendLists();
}

bool PlayerObject::hasWaypoint(unsigned long long objectID) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);
		method.addUnsignedLongParameter(objectID);

		return method.executeWithBooleanReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->hasWaypoint(objectID);
}

bool PlayerObject::hasSkill(Skill* skill) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((PlayerObjectImplementation*) _impl)->hasSkill(skill);
}

bool PlayerObject::hasSkill(const String& skillName) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);
		method.addAsciiParameter(skillName);

		return method.executeWithBooleanReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->hasSkill(skillName);
}

unsigned int PlayerObject::getCharacterBitmask() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getCharacterBitmask();
}

String PlayerObject::getTitle() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);

		method.executeWithAsciiReturn(_return_getTitle);
		return _return_getTitle;
	} else
		return ((PlayerObjectImplementation*) _impl)->getTitle();
}

unsigned int PlayerObject::getAdminLevel() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 29);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getAdminLevel();
}

void PlayerObject::setCharacterBitmask(unsigned int bitmask) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 30);
		method.addUnsignedIntParameter(bitmask);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->setCharacterBitmask(bitmask);
}

bool PlayerObject::setCharacterBit(unsigned int bit, bool notifyClient) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 31);
		method.addUnsignedIntParameter(bit);
		method.addBooleanParameter(notifyClient);

		return method.executeWithBooleanReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->setCharacterBit(bit, notifyClient);
}

bool PlayerObject::clearCharacterBit(unsigned int bit, bool notifyClient) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 32);
		method.addUnsignedIntParameter(bit);
		method.addBooleanParameter(notifyClient);

		return method.executeWithBooleanReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->clearCharacterBit(bit, notifyClient);
}

void PlayerObject::setTitle(const String& characterTitle) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 33);
		method.addAsciiParameter(characterTitle);

		method.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->setTitle(characterTitle);
}

DeltaVectorMap<String, int>* PlayerObject::getExperienceList() {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((PlayerObjectImplementation*) _impl)->getExperienceList();
}

int PlayerObject::getForcePower() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 34);

		return method.executeWithSignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getForcePower();
}

int PlayerObject::getForcePowerMax() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 35);

		return method.executeWithSignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getForcePowerMax();
}

WaypointList* PlayerObject::getWaypointList() {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((PlayerObjectImplementation*) _impl)->getWaypointList();
}

SkillList* PlayerObject::getSkills() {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((PlayerObjectImplementation*) _impl)->getSkills();
}

int PlayerObject::getFoodFilling() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 36);

		return method.executeWithSignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getFoodFilling();
}

int PlayerObject::getFoodFillingMax() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 37);

		return method.executeWithSignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getFoodFillingMax();
}

int PlayerObject::getDrinkFilling() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 38);

		return method.executeWithSignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getDrinkFilling();
}

int PlayerObject::getDrinkFillingMax() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 39);

		return method.executeWithSignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getDrinkFillingMax();
}

int PlayerObject::getJediState() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 40);

		return method.executeWithSignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getJediState();
}

byte PlayerObject::getLanguageID() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 41);

		return method.executeWithByteReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getLanguageID();
}

DeltaVector<String>* PlayerObject::getFriendList() {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((PlayerObjectImplementation*) _impl)->getFriendList();
}

DeltaVector<String>* PlayerObject::getIgnoreList() {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((PlayerObjectImplementation*) _impl)->getIgnoreList();
}

/*
 *	PlayerObjectImplementation
 */

PlayerObjectImplementation::PlayerObjectImplementation(DummyConstructorParameter* param) : IntangibleObjectImplementation(param) {
	_initializeImplementation();
}

PlayerObjectImplementation::~PlayerObjectImplementation() {
	PlayerObjectImplementation::finalize();
}


void PlayerObjectImplementation::_initializeImplementation() {
	_setClassHelper(PlayerObjectHelper::instance());

	_serializationHelperMethod();
}

void PlayerObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (PlayerObject*) stub;
	IntangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* PlayerObjectImplementation::_getStub() {
	return _this;
}

PlayerObjectImplementation::operator const PlayerObject*() {
	return _this;
}

void PlayerObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void PlayerObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void PlayerObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void PlayerObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void PlayerObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void PlayerObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void PlayerObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void PlayerObjectImplementation::_serializationHelperMethod() {
	IntangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("PlayerObject");

	addSerializableVariable("characterBitmask", &characterBitmask);
	addSerializableVariable("title", &title);
	addSerializableVariable("forcePower", &forcePower);
	addSerializableVariable("forcePowerMax", &forcePowerMax);
	addSerializableVariable("foodFilling", &foodFilling);
	addSerializableVariable("foodFillingMax", &foodFillingMax);
	addSerializableVariable("drinkFilling", &drinkFilling);
	addSerializableVariable("drinkFillingMax", &drinkFillingMax);
	addSerializableVariable("jediState", &jediState);
	addSerializableVariable("adminLevel", &adminLevel);
	addSerializableVariable("languageID", &languageID);
	addSerializableVariable("experienceList", &experienceList);
	addSerializableVariable("waypointList", &waypointList);
	addSerializableVariable("skillList", &skillList);
	addSerializableVariable("friendList", &friendList);
	addSerializableVariable("ignoreList", &ignoreList);
}

PlayerObjectImplementation::PlayerObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/player/PlayerObject.idl(117):  		Logger.setLoggingName("PlayerObject");
	Logger::setLoggingName("PlayerObject");
}

void PlayerObjectImplementation::finalize() {
}

bool PlayerObjectImplementation::hasFriend(const String& name) {
	// server/zone/objects/player/PlayerObject.idl(281):  		return friendList.contains(name);
	return (&friendList)->contains(name);
}

bool PlayerObjectImplementation::isIgnoring(const String& name) {
	// server/zone/objects/player/PlayerObject.idl(285):  		return ignoreList.contains(name);
	return (&ignoreList)->contains(name);
}

void PlayerObjectImplementation::addReverseFriend(const String& name) {
	// server/zone/objects/player/PlayerObject.idl(289):  		friendList.addReversePlayer(name);
	(&friendList)->addReversePlayer(name);
}

void PlayerObjectImplementation::removeReverseFriend(const String& name) {
	// server/zone/objects/player/PlayerObject.idl(293):  		friendList.removeReversePlayer(name);
	(&friendList)->removeReversePlayer(name);
}

bool PlayerObjectImplementation::hasWaypoint(unsigned long long objectID) {
	// server/zone/objects/player/PlayerObject.idl(299):  		return waypointList.contains(objectID);
	return (&waypointList)->contains(objectID);
}

bool PlayerObjectImplementation::hasSkill(Skill* skill) {
	// server/zone/objects/player/PlayerObject.idl(304):  		return skillList.contains(skill);
	return (&skillList)->contains(skill);
}

unsigned int PlayerObjectImplementation::getCharacterBitmask() {
	// server/zone/objects/player/PlayerObject.idl(310):  		return characterBitmask;
	return characterBitmask;
}

String PlayerObjectImplementation::getTitle() {
	// server/zone/objects/player/PlayerObject.idl(314):  		return title;
	return title;
}

unsigned int PlayerObjectImplementation::getAdminLevel() {
	// server/zone/objects/player/PlayerObject.idl(318):  		return adminLevel;
	return adminLevel;
}

void PlayerObjectImplementation::setCharacterBitmask(unsigned int bitmask) {
	// server/zone/objects/player/PlayerObject.idl(322):  		characterBitmask = bitmask;
	characterBitmask = bitmask;
}

void PlayerObjectImplementation::setTitle(const String& characterTitle) {
	// server/zone/objects/player/PlayerObject.idl(329):  		title = characterTitle;
	title = characterTitle;
}

DeltaVectorMap<String, int>* PlayerObjectImplementation::getExperienceList() {
	// server/zone/objects/player/PlayerObject.idl(334):  		return experienceList;
	return (&experienceList);
}

int PlayerObjectImplementation::getForcePower() {
	// server/zone/objects/player/PlayerObject.idl(338):  		return forcePower;
	return forcePower;
}

int PlayerObjectImplementation::getForcePowerMax() {
	// server/zone/objects/player/PlayerObject.idl(342):  		return forcePowerMax;
	return forcePowerMax;
}

WaypointList* PlayerObjectImplementation::getWaypointList() {
	// server/zone/objects/player/PlayerObject.idl(347):  		return waypointList;
	return (&waypointList);
}

SkillList* PlayerObjectImplementation::getSkills() {
	// server/zone/objects/player/PlayerObject.idl(352):  		return skillList;
	return (&skillList);
}

int PlayerObjectImplementation::getFoodFilling() {
	// server/zone/objects/player/PlayerObject.idl(356):  		return foodFilling;
	return foodFilling;
}

int PlayerObjectImplementation::getFoodFillingMax() {
	// server/zone/objects/player/PlayerObject.idl(360):  		return foodFillingMax;
	return foodFillingMax;
}

int PlayerObjectImplementation::getDrinkFilling() {
	// server/zone/objects/player/PlayerObject.idl(364):  		return drinkFilling;
	return drinkFilling;
}

int PlayerObjectImplementation::getDrinkFillingMax() {
	// server/zone/objects/player/PlayerObject.idl(368):  		return drinkFillingMax;
	return drinkFillingMax;
}

int PlayerObjectImplementation::getJediState() {
	// server/zone/objects/player/PlayerObject.idl(372):  		return jediState;
	return jediState;
}

byte PlayerObjectImplementation::getLanguageID() {
	// server/zone/objects/player/PlayerObject.idl(376):  		return languageID;
	return languageID;
}

DeltaVector<String>* PlayerObjectImplementation::getFriendList() {
	// server/zone/objects/player/PlayerObject.idl(381):  		return friendList;
	return (&friendList);
}

DeltaVector<String>* PlayerObjectImplementation::getIgnoreList() {
	// server/zone/objects/player/PlayerObject.idl(386):  		return ignoreList;
	return (&ignoreList);
}

/*
 *	PlayerObjectAdapter
 */

PlayerObjectAdapter::PlayerObjectAdapter(PlayerObjectImplementation* obj) : IntangibleObjectAdapter(obj) {
}

Packet* PlayerObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		finalize();
		break;
	case 7:
		initializeTransientMembers();
		break;
	case 8:
		sendBaselinesTo((SceneObject*) inv->getObjectParameter());
		break;
	case 9:
		sendMessage((BasePacket*) inv->getObjectParameter());
		break;
	case 10:
		addExperience(inv->getAsciiParameter(_param0_addExperience__String_int_bool_), inv->getSignedIntParameter(), inv->getBooleanParameter());
		break;
	case 11:
		removeExperience(inv->getAsciiParameter(_param0_removeExperience__String_bool_), inv->getBooleanParameter());
		break;
	case 12:
		addWaypoint(inv->getAsciiParameter(_param0_addWaypoint__String_float_float_bool_), inv->getFloatParameter(), inv->getFloatParameter(), inv->getBooleanParameter());
		break;
	case 13:
		removeWaypoint(inv->getUnsignedLongParameter(), inv->getBooleanParameter());
		break;
	case 14:
		setLanguageID(inv->getByteParameter(), inv->getBooleanParameter());
		break;
	case 15:
		addFriend(inv->getAsciiParameter(_param0_addFriend__String_bool_), inv->getBooleanParameter());
		break;
	case 16:
		removeFriend(inv->getAsciiParameter(_param0_removeFriend__String_bool_), inv->getBooleanParameter());
		break;
	case 17:
		addIgnore(inv->getAsciiParameter(_param0_addIgnore__String_bool_), inv->getBooleanParameter());
		break;
	case 18:
		removeIgnore(inv->getAsciiParameter(_param0_removeIgnore__String_bool_), inv->getBooleanParameter());
		break;
	case 19:
		notifyOnline();
		break;
	case 20:
		notifyOffline();
		break;
	case 21:
		resp->insertBoolean(hasFriend(inv->getAsciiParameter(_param0_hasFriend__String_)));
		break;
	case 22:
		resp->insertBoolean(isIgnoring(inv->getAsciiParameter(_param0_isIgnoring__String_)));
		break;
	case 23:
		addReverseFriend(inv->getAsciiParameter(_param0_addReverseFriend__String_));
		break;
	case 24:
		removeReverseFriend(inv->getAsciiParameter(_param0_removeReverseFriend__String_));
		break;
	case 25:
		sendFriendLists();
		break;
	case 26:
		resp->insertBoolean(hasWaypoint(inv->getUnsignedLongParameter()));
		break;
	case 27:
		resp->insertBoolean(hasSkill(inv->getAsciiParameter(_param0_hasSkill__String_)));
		break;
	case 28:
		resp->insertInt(getCharacterBitmask());
		break;
	case 29:
		resp->insertAscii(getTitle());
		break;
	case 30:
		resp->insertInt(getAdminLevel());
		break;
	case 31:
		setCharacterBitmask(inv->getUnsignedIntParameter());
		break;
	case 32:
		resp->insertBoolean(setCharacterBit(inv->getUnsignedIntParameter(), inv->getBooleanParameter()));
		break;
	case 33:
		resp->insertBoolean(clearCharacterBit(inv->getUnsignedIntParameter(), inv->getBooleanParameter()));
		break;
	case 34:
		setTitle(inv->getAsciiParameter(_param0_setTitle__String_));
		break;
	case 35:
		resp->insertSignedInt(getForcePower());
		break;
	case 36:
		resp->insertSignedInt(getForcePowerMax());
		break;
	case 37:
		resp->insertSignedInt(getFoodFilling());
		break;
	case 38:
		resp->insertSignedInt(getFoodFillingMax());
		break;
	case 39:
		resp->insertSignedInt(getDrinkFilling());
		break;
	case 40:
		resp->insertSignedInt(getDrinkFillingMax());
		break;
	case 41:
		resp->insertSignedInt(getJediState());
		break;
	case 42:
		resp->insertByte(getLanguageID());
		break;
	default:
		return NULL;
	}

	return resp;
}

void PlayerObjectAdapter::finalize() {
	((PlayerObjectImplementation*) impl)->finalize();
}

void PlayerObjectAdapter::initializeTransientMembers() {
	((PlayerObjectImplementation*) impl)->initializeTransientMembers();
}

void PlayerObjectAdapter::sendBaselinesTo(SceneObject* player) {
	((PlayerObjectImplementation*) impl)->sendBaselinesTo(player);
}

void PlayerObjectAdapter::sendMessage(BasePacket* msg) {
	((PlayerObjectImplementation*) impl)->sendMessage(msg);
}

void PlayerObjectAdapter::addExperience(const String& xpType, int xp, bool notifyClient) {
	((PlayerObjectImplementation*) impl)->addExperience(xpType, xp, notifyClient);
}

void PlayerObjectAdapter::removeExperience(const String& xpType, bool notifyClient) {
	((PlayerObjectImplementation*) impl)->removeExperience(xpType, notifyClient);
}

void PlayerObjectAdapter::addWaypoint(const String& planet, float positionX, float positionY, bool notifyClient) {
	((PlayerObjectImplementation*) impl)->addWaypoint(planet, positionX, positionY, notifyClient);
}

void PlayerObjectAdapter::removeWaypoint(unsigned long long waypointID, bool notifyClient) {
	((PlayerObjectImplementation*) impl)->removeWaypoint(waypointID, notifyClient);
}

void PlayerObjectAdapter::setLanguageID(byte language, bool notifyClient) {
	((PlayerObjectImplementation*) impl)->setLanguageID(language, notifyClient);
}

void PlayerObjectAdapter::addFriend(const String& name, bool notifyClient) {
	((PlayerObjectImplementation*) impl)->addFriend(name, notifyClient);
}

void PlayerObjectAdapter::removeFriend(const String& name, bool notifyClient) {
	((PlayerObjectImplementation*) impl)->removeFriend(name, notifyClient);
}

void PlayerObjectAdapter::addIgnore(const String& name, bool notifyClient) {
	((PlayerObjectImplementation*) impl)->addIgnore(name, notifyClient);
}

void PlayerObjectAdapter::removeIgnore(const String& name, bool notifyClient) {
	((PlayerObjectImplementation*) impl)->removeIgnore(name, notifyClient);
}

void PlayerObjectAdapter::notifyOnline() {
	((PlayerObjectImplementation*) impl)->notifyOnline();
}

void PlayerObjectAdapter::notifyOffline() {
	((PlayerObjectImplementation*) impl)->notifyOffline();
}

bool PlayerObjectAdapter::hasFriend(const String& name) {
	return ((PlayerObjectImplementation*) impl)->hasFriend(name);
}

bool PlayerObjectAdapter::isIgnoring(const String& name) {
	return ((PlayerObjectImplementation*) impl)->isIgnoring(name);
}

void PlayerObjectAdapter::addReverseFriend(const String& name) {
	((PlayerObjectImplementation*) impl)->addReverseFriend(name);
}

void PlayerObjectAdapter::removeReverseFriend(const String& name) {
	((PlayerObjectImplementation*) impl)->removeReverseFriend(name);
}

void PlayerObjectAdapter::sendFriendLists() {
	((PlayerObjectImplementation*) impl)->sendFriendLists();
}

bool PlayerObjectAdapter::hasWaypoint(unsigned long long objectID) {
	return ((PlayerObjectImplementation*) impl)->hasWaypoint(objectID);
}

bool PlayerObjectAdapter::hasSkill(const String& skillName) {
	return ((PlayerObjectImplementation*) impl)->hasSkill(skillName);
}

unsigned int PlayerObjectAdapter::getCharacterBitmask() {
	return ((PlayerObjectImplementation*) impl)->getCharacterBitmask();
}

String PlayerObjectAdapter::getTitle() {
	return ((PlayerObjectImplementation*) impl)->getTitle();
}

unsigned int PlayerObjectAdapter::getAdminLevel() {
	return ((PlayerObjectImplementation*) impl)->getAdminLevel();
}

void PlayerObjectAdapter::setCharacterBitmask(unsigned int bitmask) {
	((PlayerObjectImplementation*) impl)->setCharacterBitmask(bitmask);
}

bool PlayerObjectAdapter::setCharacterBit(unsigned int bit, bool notifyClient) {
	return ((PlayerObjectImplementation*) impl)->setCharacterBit(bit, notifyClient);
}

bool PlayerObjectAdapter::clearCharacterBit(unsigned int bit, bool notifyClient) {
	return ((PlayerObjectImplementation*) impl)->clearCharacterBit(bit, notifyClient);
}

void PlayerObjectAdapter::setTitle(const String& characterTitle) {
	((PlayerObjectImplementation*) impl)->setTitle(characterTitle);
}

int PlayerObjectAdapter::getForcePower() {
	return ((PlayerObjectImplementation*) impl)->getForcePower();
}

int PlayerObjectAdapter::getForcePowerMax() {
	return ((PlayerObjectImplementation*) impl)->getForcePowerMax();
}

int PlayerObjectAdapter::getFoodFilling() {
	return ((PlayerObjectImplementation*) impl)->getFoodFilling();
}

int PlayerObjectAdapter::getFoodFillingMax() {
	return ((PlayerObjectImplementation*) impl)->getFoodFillingMax();
}

int PlayerObjectAdapter::getDrinkFilling() {
	return ((PlayerObjectImplementation*) impl)->getDrinkFilling();
}

int PlayerObjectAdapter::getDrinkFillingMax() {
	return ((PlayerObjectImplementation*) impl)->getDrinkFillingMax();
}

int PlayerObjectAdapter::getJediState() {
	return ((PlayerObjectImplementation*) impl)->getJediState();
}

byte PlayerObjectAdapter::getLanguageID() {
	return ((PlayerObjectImplementation*) impl)->getLanguageID();
}

/*
 *	PlayerObjectHelper
 */

PlayerObjectHelper* PlayerObjectHelper::staticInitializer = PlayerObjectHelper::instance();

PlayerObjectHelper::PlayerObjectHelper() {
	className = "PlayerObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void PlayerObjectHelper::finalizeHelper() {
	PlayerObjectHelper::finalize();
}

DistributedObject* PlayerObjectHelper::instantiateObject() {
	return new PlayerObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* PlayerObjectHelper::instantiateServant() {
	return new PlayerObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* PlayerObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new PlayerObjectAdapter((PlayerObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

