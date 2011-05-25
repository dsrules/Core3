/*
 *	server/zone/objects/creature/buffs/DelayedBuff.cpp generated by engine3 IDL compiler 0.60
 */

#include "DelayedBuff.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/buffs/BuffDurationEvent.h"


// Imported class dependencies

#include "engine/core/ManagedObject.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "engine/service/proto/BaseMessage.h"

#include "engine/service/proto/BasePacket.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "server/chat/StringIdChatParameter.h"

#include "server/chat/room/ChatRoom.h"

#include "server/login/account/Account.h"

#include "server/login/account/AccountManager.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/SpeedMultiplierModChanges.h"

#include "server/zone/objects/creature/buffs/Buff.h"

#include "server/zone/objects/creature/buffs/BuffDurationEvent.h"

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

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "system/io/ObjectInputStream.h"

#include "system/io/ObjectOutputStream.h"

#include "system/lang/Time.h"

#include "system/util/SortedVector.h"

#include "system/util/Vector.h"

#include "system/util/VectorMap.h"

/*
 *	DelayedBuffStub
 */

enum {RPC_ACTIVATE__ = 6,RPC_DEACTIVATE__,RPC_USECHARGE__CREATUREOBJECT_,RPC_SETUSESREMAINING__INT_};

DelayedBuff::DelayedBuff(CreatureObject* creo, unsigned int buffcrc, int duration) : Buff(DummyConstructorParameter::instance()) {
	DelayedBuffImplementation* _implementation = new DelayedBuffImplementation(creo, buffcrc, duration);
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

DelayedBuff::DelayedBuff(DummyConstructorParameter* param) : Buff(param) {
}

DelayedBuff::~DelayedBuff() {
}


void DelayedBuff::activate() {
	DelayedBuffImplementation* _implementation = (DelayedBuffImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ACTIVATE__);

		method.executeWithVoidReturn();
	} else
		_implementation->activate();
}

void DelayedBuff::deactivate() {
	DelayedBuffImplementation* _implementation = (DelayedBuffImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DEACTIVATE__);

		method.executeWithVoidReturn();
	} else
		_implementation->deactivate();
}

void DelayedBuff::useCharge(CreatureObject* creature) {
	DelayedBuffImplementation* _implementation = (DelayedBuffImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_USECHARGE__CREATUREOBJECT_);
		method.addObjectParameter(creature);

		method.executeWithVoidReturn();
	} else
		_implementation->useCharge(creature);
}

void DelayedBuff::setUsesRemaining(int uses) {
	DelayedBuffImplementation* _implementation = (DelayedBuffImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETUSESREMAINING__INT_);
		method.addSignedIntParameter(uses);

		method.executeWithVoidReturn();
	} else
		_implementation->setUsesRemaining(uses);
}

DistributedObjectServant* DelayedBuff::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void DelayedBuff::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<DelayedBuffImplementation*>(servant));
}

/*
 *	DelayedBuffImplementation
 */

DelayedBuffImplementation::DelayedBuffImplementation(DummyConstructorParameter* param) : BuffImplementation(param) {
	_initializeImplementation();
}


DelayedBuffImplementation::~DelayedBuffImplementation() {
}


void DelayedBuffImplementation::finalize() {
}

void DelayedBuffImplementation::_initializeImplementation() {
	_setClassHelper(DelayedBuffHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void DelayedBuffImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (DelayedBuff*) stub;
	BuffImplementation::_setStub(stub);
}

DistributedObjectStub* DelayedBuffImplementation::_getStub() {
	return _this;
}

DelayedBuffImplementation::operator const DelayedBuff*() {
	return _this;
}

Object* DelayedBuffImplementation::clone() {
	return dynamic_cast<Object*>(new DelayedBuffImplementation(*this));
}


void DelayedBuffImplementation::lock(bool doLock) {
}

void DelayedBuffImplementation::lock(ManagedObject* obj) {
}

void DelayedBuffImplementation::rlock(bool doLock) {
}

void DelayedBuffImplementation::wlock(bool doLock) {
}

void DelayedBuffImplementation::wlock(ManagedObject* obj) {
}

void DelayedBuffImplementation::unlock(bool doLock) {
}

void DelayedBuffImplementation::runlock(bool doLock) {
}

void DelayedBuffImplementation::_serializationHelperMethod() {
	BuffImplementation::_serializationHelperMethod();

	_setClassName("DelayedBuff");

}

void DelayedBuffImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(DelayedBuffImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool DelayedBuffImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (BuffImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "usesRemaining") {
		TypeInfo<int >::parseFromBinaryStream(&usesRemaining, stream);
		return true;
	}


	return false;
}

void DelayedBuffImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = DelayedBuffImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int DelayedBuffImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "usesRemaining";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&usesRemaining, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + BuffImplementation::writeObjectMembers(stream);
}

DelayedBuffImplementation::DelayedBuffImplementation(CreatureObject* creo, unsigned int buffcrc, int duration) : BuffImplementation(creo, buffcrc, 1380, BuffType::FOOD) {
	_initializeImplementation();
	// server/zone/objects/creature/buffs/DelayedBuff.idl():  		usesRemaining = duration;
	usesRemaining = duration;
}

void DelayedBuffImplementation::activate() {
	// server/zone/objects/creature/buffs/DelayedBuff.idl():  		super.activate(false);
	BuffImplementation::activate(false);
}

void DelayedBuffImplementation::deactivate() {
	// server/zone/objects/creature/buffs/DelayedBuff.idl():  		super.deactivate(false);
	BuffImplementation::deactivate(false);
}

void DelayedBuffImplementation::useCharge(CreatureObject* creature) {
	// server/zone/objects/creature/buffs/DelayedBuff.idl():  		usesRemaining = usesRemaining - 1;
	usesRemaining = usesRemaining - 1;
	// server/zone/objects/creature/buffs/DelayedBuff.idl():  	}
	if (usesRemaining < 1){
	// server/zone/objects/creature/buffs/DelayedBuff.idl():  			creature.removeBuff(this);
	creature->removeBuff(_this);
}
}

void DelayedBuffImplementation::setUsesRemaining(int uses) {
	// server/zone/objects/creature/buffs/DelayedBuff.idl():  		usesRemaining = uses;
	usesRemaining = uses;
}

/*
 *	DelayedBuffAdapter
 */

DelayedBuffAdapter::DelayedBuffAdapter(DelayedBuffImplementation* obj) : BuffAdapter(obj) {
}

Packet* DelayedBuffAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_ACTIVATE__:
		activate();
		break;
	case RPC_DEACTIVATE__:
		deactivate();
		break;
	case RPC_USECHARGE__CREATUREOBJECT_:
		useCharge((CreatureObject*) inv->getObjectParameter());
		break;
	case RPC_SETUSESREMAINING__INT_:
		setUsesRemaining(inv->getSignedIntParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void DelayedBuffAdapter::activate() {
	((DelayedBuffImplementation*) impl)->activate();
}

void DelayedBuffAdapter::deactivate() {
	((DelayedBuffImplementation*) impl)->deactivate();
}

void DelayedBuffAdapter::useCharge(CreatureObject* creature) {
	((DelayedBuffImplementation*) impl)->useCharge(creature);
}

void DelayedBuffAdapter::setUsesRemaining(int uses) {
	((DelayedBuffImplementation*) impl)->setUsesRemaining(uses);
}

/*
 *	DelayedBuffHelper
 */

DelayedBuffHelper* DelayedBuffHelper::staticInitializer = DelayedBuffHelper::instance();

DelayedBuffHelper::DelayedBuffHelper() {
	className = "DelayedBuff";

	Core::getObjectBroker()->registerClass(className, this);
}

void DelayedBuffHelper::finalizeHelper() {
	DelayedBuffHelper::finalize();
}

DistributedObject* DelayedBuffHelper::instantiateObject() {
	return new DelayedBuff(DummyConstructorParameter::instance());
}

DistributedObjectServant* DelayedBuffHelper::instantiateServant() {
	return new DelayedBuffImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DelayedBuffHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DelayedBuffAdapter((DelayedBuffImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

