/*
 *	server/zone/objects/tangible/sign/SignObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "SignObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/Zone.h"


// Imported class dependencies

#include "engine/core/ManagedObject.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "engine/core/Task.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "engine/service/proto/BaseMessage.h"

#include "engine/service/proto/BasePacket.h"

#include "engine/stm/TransactionalReference.h"

#include "engine/util/Facade.h"

#include "engine/util/Observable.h"

#include "engine/util/Observer.h"

#include "engine/util/ObserverEventMap.h"

#include "engine/util/u3d/Coordinate.h"

#include "engine/util/u3d/QuadTree.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "engine/util/u3d/QuadTreeNode.h"

#include "engine/util/u3d/Quaternion.h"

#include "server/chat/StringIdChatParameter.h"

#include "server/chat/room/ChatRoom.h"

#include "server/login/account/Account.h"

#include "server/login/account/AccountManager.h"

#include "server/zone/Zone.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/ZonePacketHandler.h"

#include "server/zone/ZoneProcessServer.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/managers/city/CityManager.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "server/zone/managers/planet/PlanetManager.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "server/zone/objects/cell/CellObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/SpeedMultiplierModChanges.h"

#include "server/zone/objects/creature/buffs/Buff.h"

#include "server/zone/objects/creature/buffs/BuffList.h"

#include "server/zone/objects/creature/damageovertime/DamageOverTimeList.h"

#include "server/zone/objects/creature/professions/SkillBox.h"

#include "server/zone/objects/creature/variables/CommandQueueAction.h"

#include "server/zone/objects/creature/variables/CooldownTimerMap.h"

#include "server/zone/objects/creature/variables/SkillBoxList.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

#include "server/zone/objects/group/GroupList.h"

#include "server/zone/objects/group/GroupObject.h"

#include "server/zone/objects/guild/GuildObject.h"

#include "server/zone/objects/intangible/ControlDevice.h"

#include "server/zone/objects/manufactureschematic/IngredientSlots.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "system/io/ObjectInputStream.h"

#include "system/io/ObjectOutputStream.h"

#include "system/lang/Time.h"

#include "system/util/SortedVector.h"

#include "system/util/Vector.h"

#include "system/util/VectorMap.h"

/*
 *	SignObjectStub
 */

enum {RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_ = 6,RPC_SENDSIGNNAMETO__PLAYERCREATURE_,RPC_ISSIGNOBJECT__};

SignObject::SignObject() : TangibleObject(DummyConstructorParameter::instance()) {
	SignObjectImplementation* _implementation = new SignObjectImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

SignObject::SignObject(DummyConstructorParameter* param) : TangibleObject(param) {
}

SignObject::~SignObject() {
}


int SignObject::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	SignObjectImplementation* _implementation = (SignObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

void SignObject::sendSignNameTo(PlayerCreature* player) {
	SignObjectImplementation* _implementation = (SignObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDSIGNNAMETO__PLAYERCREATURE_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendSignNameTo(player);
}

bool SignObject::isSignObject() {
	SignObjectImplementation* _implementation = (SignObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISSIGNOBJECT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isSignObject();
}

DistributedObjectServant* SignObject::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void SignObject::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<SignObjectImplementation*>(servant));
}

/*
 *	SignObjectImplementation
 */

SignObjectImplementation::SignObjectImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


SignObjectImplementation::~SignObjectImplementation() {
}


void SignObjectImplementation::finalize() {
}

void SignObjectImplementation::_initializeImplementation() {
	_setClassHelper(SignObjectHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void SignObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (SignObject*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* SignObjectImplementation::_getStub() {
	return _this;
}

SignObjectImplementation::operator const SignObject*() {
	return _this;
}

Object* SignObjectImplementation::clone() {
	return dynamic_cast<Object*>(new SignObjectImplementation(*this));
}


void SignObjectImplementation::lock(bool doLock) {
}

void SignObjectImplementation::lock(ManagedObject* obj) {
}

void SignObjectImplementation::rlock(bool doLock) {
}

void SignObjectImplementation::wlock(bool doLock) {
}

void SignObjectImplementation::wlock(ManagedObject* obj) {
}

void SignObjectImplementation::unlock(bool doLock) {
}

void SignObjectImplementation::runlock(bool doLock) {
}

void SignObjectImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("SignObject");

}

void SignObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(SignObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool SignObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TangibleObjectImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void SignObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = SignObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int SignObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + TangibleObjectImplementation::writeObjectMembers(stream);
}

SignObjectImplementation::SignObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/sign/SignObject.idl():  		Logger.setLoggingName("SignObject");
	Logger::setLoggingName("SignObject");
}

bool SignObjectImplementation::isSignObject() {
	// server/zone/objects/tangible/sign/SignObject.idl():  		return true;
	return true;
}

/*
 *	SignObjectAdapter
 */

SignObjectAdapter::SignObjectAdapter(SignObjectImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* SignObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case RPC_SENDSIGNNAMETO__PLAYERCREATURE_:
		sendSignNameTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case RPC_ISSIGNOBJECT__:
		resp->insertBoolean(isSignObject());
		break;
	default:
		return NULL;
	}

	return resp;
}

int SignObjectAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((SignObjectImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

void SignObjectAdapter::sendSignNameTo(PlayerCreature* player) {
	((SignObjectImplementation*) impl)->sendSignNameTo(player);
}

bool SignObjectAdapter::isSignObject() {
	return ((SignObjectImplementation*) impl)->isSignObject();
}

/*
 *	SignObjectHelper
 */

SignObjectHelper* SignObjectHelper::staticInitializer = SignObjectHelper::instance();

SignObjectHelper::SignObjectHelper() {
	className = "SignObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void SignObjectHelper::finalizeHelper() {
	SignObjectHelper::finalize();
}

DistributedObject* SignObjectHelper::instantiateObject() {
	return new SignObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* SignObjectHelper::instantiateServant() {
	return new SignObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SignObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SignObjectAdapter((SignObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

