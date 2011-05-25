/*
 *	server/zone/objects/creature/buffs/SpiceDownerBuff.cpp generated by engine3 IDL compiler 0.60
 */

#include "SpiceDownerBuff.h"

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
 *	SpiceDownerBuffStub
 */

enum {RPC_ACTIVATE__BOOL_ = 6,RPC_DEACTIVATE__BOOL_};

SpiceDownerBuff::SpiceDownerBuff(CreatureObject* creo, const String& name, unsigned int buffCRC, int duration) : Buff(DummyConstructorParameter::instance()) {
	SpiceDownerBuffImplementation* _implementation = new SpiceDownerBuffImplementation(creo, name, buffCRC, duration);
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

SpiceDownerBuff::SpiceDownerBuff(DummyConstructorParameter* param) : Buff(param) {
}

SpiceDownerBuff::~SpiceDownerBuff() {
}


void SpiceDownerBuff::activate(bool applyModifiers) {
	SpiceDownerBuffImplementation* _implementation = (SpiceDownerBuffImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ACTIVATE__BOOL_);
		method.addBooleanParameter(applyModifiers);

		method.executeWithVoidReturn();
	} else
		_implementation->activate(applyModifiers);
}

void SpiceDownerBuff::deactivate(bool applyModifiers) {
	SpiceDownerBuffImplementation* _implementation = (SpiceDownerBuffImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DEACTIVATE__BOOL_);
		method.addBooleanParameter(applyModifiers);

		method.executeWithVoidReturn();
	} else
		_implementation->deactivate(applyModifiers);
}

DistributedObjectServant* SpiceDownerBuff::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void SpiceDownerBuff::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<SpiceDownerBuffImplementation*>(servant));
}

/*
 *	SpiceDownerBuffImplementation
 */

SpiceDownerBuffImplementation::SpiceDownerBuffImplementation(DummyConstructorParameter* param) : BuffImplementation(param) {
	_initializeImplementation();
}


SpiceDownerBuffImplementation::~SpiceDownerBuffImplementation() {
}


void SpiceDownerBuffImplementation::finalize() {
}

void SpiceDownerBuffImplementation::_initializeImplementation() {
	_setClassHelper(SpiceDownerBuffHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void SpiceDownerBuffImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (SpiceDownerBuff*) stub;
	BuffImplementation::_setStub(stub);
}

DistributedObjectStub* SpiceDownerBuffImplementation::_getStub() {
	return _this;
}

SpiceDownerBuffImplementation::operator const SpiceDownerBuff*() {
	return _this;
}

Object* SpiceDownerBuffImplementation::clone() {
	return dynamic_cast<Object*>(new SpiceDownerBuffImplementation(*this));
}


void SpiceDownerBuffImplementation::lock(bool doLock) {
}

void SpiceDownerBuffImplementation::lock(ManagedObject* obj) {
}

void SpiceDownerBuffImplementation::rlock(bool doLock) {
}

void SpiceDownerBuffImplementation::wlock(bool doLock) {
}

void SpiceDownerBuffImplementation::wlock(ManagedObject* obj) {
}

void SpiceDownerBuffImplementation::unlock(bool doLock) {
}

void SpiceDownerBuffImplementation::runlock(bool doLock) {
}

void SpiceDownerBuffImplementation::_serializationHelperMethod() {
	BuffImplementation::_serializationHelperMethod();

	_setClassName("SpiceDownerBuff");

}

void SpiceDownerBuffImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(SpiceDownerBuffImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool SpiceDownerBuffImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (BuffImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void SpiceDownerBuffImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = SpiceDownerBuffImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int SpiceDownerBuffImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + BuffImplementation::writeObjectMembers(stream);
}

SpiceDownerBuffImplementation::SpiceDownerBuffImplementation(CreatureObject* creo, const String& name, unsigned int buffCRC, int duration) : BuffImplementation(creo, buffCRC, duration, BuffType::SPICE) {
	_initializeImplementation();
	// server/zone/objects/creature/buffs/SpiceDownerBuff.idl():  		super.buffName = name;
	BuffImplementation::buffName = name;
}

void SpiceDownerBuffImplementation::activate(bool applyModifiers) {
	// server/zone/objects/creature/buffs/SpiceDownerBuff.idl():  		super.creature.sendSystemMessage("spice/spice", super.buffName + "_downer");
	BuffImplementation::creature.getForUpdate()->sendSystemMessage("spice/spice", BuffImplementation::buffName + "_downer");
	// server/zone/objects/creature/buffs/SpiceDownerBuff.idl():  		}
	if (BuffImplementation::creature.getForUpdate()->hasBuff(BuffCRC::FOOD_REDUCE_SPICE_DOWNTIME)){
	// server/zone/objects/creature/buffs/SpiceDownerBuff.idl():  			Buff buff = super.creature.getBuff(BuffCRC.FOOD_REDUCE_SPICE_DOWNTIME);
	Buff* buff = BuffImplementation::creature.getForUpdate()->getBuff(BuffCRC::FOOD_REDUCE_SPICE_DOWNTIME);
	// server/zone/objects/creature/buffs/SpiceDownerBuff.idl():  			}
	if (buff != NULL){
	// server/zone/objects/creature/buffs/SpiceDownerBuff.idl():  				super.buffDuration = super.buffDuration * (100.0 - buff.getSkillModifierValue("reduce_spice_downtime")) / 100.0;
	BuffImplementation::buffDuration = BuffImplementation::buffDuration * (100.0 - buff->getSkillModifierValue("reduce_spice_downtime")) / 100.0;
	// server/zone/objects/creature/buffs/SpiceDownerBuff.idl():  				super.creature.removeBuff(buff);
	BuffImplementation::creature.getForUpdate()->removeBuff(buff);
}

	else {
}
	// server/zone/objects/creature/buffs/SpiceDownerBuff.idl():  			super.activate(applyModifiers);
	BuffImplementation::activate(applyModifiers);
}

	else {
	// server/zone/objects/creature/buffs/SpiceDownerBuff.idl():  			super.activate(applyModifiers);
	BuffImplementation::activate(applyModifiers);
}
}

void SpiceDownerBuffImplementation::deactivate(bool applyModifiers) {
	// server/zone/objects/creature/buffs/SpiceDownerBuff.idl():  		super.creature.sendSystemMessage("spice/spice", super.buffName + "_done");
	BuffImplementation::creature.getForUpdate()->sendSystemMessage("spice/spice", BuffImplementation::buffName + "_done");
	// server/zone/objects/creature/buffs/SpiceDownerBuff.idl():  		super.deactivate(applyModifiers);
	BuffImplementation::deactivate(applyModifiers);
}

/*
 *	SpiceDownerBuffAdapter
 */

SpiceDownerBuffAdapter::SpiceDownerBuffAdapter(SpiceDownerBuffImplementation* obj) : BuffAdapter(obj) {
}

Packet* SpiceDownerBuffAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_ACTIVATE__BOOL_:
		activate(inv->getBooleanParameter());
		break;
	case RPC_DEACTIVATE__BOOL_:
		deactivate(inv->getBooleanParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void SpiceDownerBuffAdapter::activate(bool applyModifiers) {
	((SpiceDownerBuffImplementation*) impl)->activate(applyModifiers);
}

void SpiceDownerBuffAdapter::deactivate(bool applyModifiers) {
	((SpiceDownerBuffImplementation*) impl)->deactivate(applyModifiers);
}

/*
 *	SpiceDownerBuffHelper
 */

SpiceDownerBuffHelper* SpiceDownerBuffHelper::staticInitializer = SpiceDownerBuffHelper::instance();

SpiceDownerBuffHelper::SpiceDownerBuffHelper() {
	className = "SpiceDownerBuff";

	Core::getObjectBroker()->registerClass(className, this);
}

void SpiceDownerBuffHelper::finalizeHelper() {
	SpiceDownerBuffHelper::finalize();
}

DistributedObject* SpiceDownerBuffHelper::instantiateObject() {
	return new SpiceDownerBuff(DummyConstructorParameter::instance());
}

DistributedObjectServant* SpiceDownerBuffHelper::instantiateServant() {
	return new SpiceDownerBuffImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SpiceDownerBuffHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SpiceDownerBuffAdapter((SpiceDownerBuffImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

