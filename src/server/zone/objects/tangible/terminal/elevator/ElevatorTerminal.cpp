/*
 *	server/zone/objects/tangible/terminal/elevator/ElevatorTerminal.cpp generated by engine3 IDL compiler 0.60
 */

#include "ElevatorTerminal.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/Zone.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"


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
 *	ElevatorTerminalStub
 */

enum {RPC_FILLOBJECTMENURESPONSE__OBJECTMENURESPONSE_PLAYERCREATURE_,RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_,RPC_ISELEVATORTERMINAL__,RPC_SETELEVATORUP__ELEVATORTERMINAL_,RPC_SETELEVATORDOWN__ELEVATORTERMINAL_,RPC_GETELEVATORUP__,RPC_GETELEVATORDOWN__};

ElevatorTerminal::ElevatorTerminal() : Terminal(DummyConstructorParameter::instance()) {
	ElevatorTerminalImplementation* _implementation = new ElevatorTerminalImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

ElevatorTerminal::ElevatorTerminal(DummyConstructorParameter* param) : Terminal(param) {
}

ElevatorTerminal::~ElevatorTerminal() {
}


void ElevatorTerminal::notifyInsert(QuadTreeEntry* obj) {
	ElevatorTerminalImplementation* _implementation = (ElevatorTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->notifyInsert(obj);
}

void ElevatorTerminal::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player) {
	ElevatorTerminalImplementation* _implementation = (ElevatorTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_FILLOBJECTMENURESPONSE__OBJECTMENURESPONSE_PLAYERCREATURE_);
		method.addObjectParameter(menuResponse);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->fillObjectMenuResponse(menuResponse, player);
}

int ElevatorTerminal::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	ElevatorTerminalImplementation* _implementation = (ElevatorTerminalImplementation*) _getImplementation();
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

bool ElevatorTerminal::isElevatorTerminal() {
	ElevatorTerminalImplementation* _implementation = (ElevatorTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISELEVATORTERMINAL__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isElevatorTerminal();
}

void ElevatorTerminal::setElevatorUp(ElevatorTerminal* term) {
	ElevatorTerminalImplementation* _implementation = (ElevatorTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETELEVATORUP__ELEVATORTERMINAL_);
		method.addObjectParameter(term);

		method.executeWithVoidReturn();
	} else
		_implementation->setElevatorUp(term);
}

void ElevatorTerminal::setElevatorDown(ElevatorTerminal* term) {
	ElevatorTerminalImplementation* _implementation = (ElevatorTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETELEVATORDOWN__ELEVATORTERMINAL_);
		method.addObjectParameter(term);

		method.executeWithVoidReturn();
	} else
		_implementation->setElevatorDown(term);
}

ElevatorTerminal* ElevatorTerminal::getElevatorUp() {
	ElevatorTerminalImplementation* _implementation = (ElevatorTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETELEVATORUP__);

		return (ElevatorTerminal*) method.executeWithObjectReturn();
	} else
		return _implementation->getElevatorUp();
}

ElevatorTerminal* ElevatorTerminal::getElevatorDown() {
	ElevatorTerminalImplementation* _implementation = (ElevatorTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETELEVATORDOWN__);

		return (ElevatorTerminal*) method.executeWithObjectReturn();
	} else
		return _implementation->getElevatorDown();
}

DistributedObjectServant* ElevatorTerminal::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void ElevatorTerminal::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<ElevatorTerminalImplementation*>(servant));
}

/*
 *	ElevatorTerminalImplementation
 */

ElevatorTerminalImplementation::ElevatorTerminalImplementation(DummyConstructorParameter* param) : TerminalImplementation(param) {
	_initializeImplementation();
}


ElevatorTerminalImplementation::~ElevatorTerminalImplementation() {
}


void ElevatorTerminalImplementation::finalize() {
}

void ElevatorTerminalImplementation::_initializeImplementation() {
	_setClassHelper(ElevatorTerminalHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void ElevatorTerminalImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ElevatorTerminal*) stub;
	TerminalImplementation::_setStub(stub);
}

DistributedObjectStub* ElevatorTerminalImplementation::_getStub() {
	return _this;
}

ElevatorTerminalImplementation::operator const ElevatorTerminal*() {
	return _this;
}

Object* ElevatorTerminalImplementation::clone() {
	return dynamic_cast<Object*>(new ElevatorTerminalImplementation(*this));
}


void ElevatorTerminalImplementation::lock(bool doLock) {
}

void ElevatorTerminalImplementation::lock(ManagedObject* obj) {
}

void ElevatorTerminalImplementation::rlock(bool doLock) {
}

void ElevatorTerminalImplementation::wlock(bool doLock) {
}

void ElevatorTerminalImplementation::wlock(ManagedObject* obj) {
}

void ElevatorTerminalImplementation::unlock(bool doLock) {
}

void ElevatorTerminalImplementation::runlock(bool doLock) {
}

void ElevatorTerminalImplementation::_serializationHelperMethod() {
	TerminalImplementation::_serializationHelperMethod();

	_setClassName("ElevatorTerminal");

}

void ElevatorTerminalImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(ElevatorTerminalImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ElevatorTerminalImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TerminalImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "elevatorUp") {
		TypeInfo<ManagedReference<ElevatorTerminal* > >::parseFromBinaryStream(&elevatorUp, stream);
		return true;
	}

	if (_name == "elevatorDown") {
		TypeInfo<ManagedReference<ElevatorTerminal* > >::parseFromBinaryStream(&elevatorDown, stream);
		return true;
	}


	return false;
}

void ElevatorTerminalImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ElevatorTerminalImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ElevatorTerminalImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "elevatorUp";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<ElevatorTerminal* > >::toBinaryStream(&elevatorUp, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "elevatorDown";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<ElevatorTerminal* > >::toBinaryStream(&elevatorDown, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 2 + TerminalImplementation::writeObjectMembers(stream);
}

ElevatorTerminalImplementation::ElevatorTerminalImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/terminal/elevator/ElevatorTerminal.idl():  		Logger.setLoggingName("ElevatorTerminal");
	Logger::setLoggingName("ElevatorTerminal");
	// server/zone/objects/tangible/terminal/elevator/ElevatorTerminal.idl():  		elevatorUp = null;
	elevatorUp = NULL;
	// server/zone/objects/tangible/terminal/elevator/ElevatorTerminal.idl():  		elevatorDown = null;
	elevatorDown = NULL;
}

bool ElevatorTerminalImplementation::isElevatorTerminal() {
	// server/zone/objects/tangible/terminal/elevator/ElevatorTerminal.idl():  		return true;
	return true;
}

void ElevatorTerminalImplementation::setElevatorUp(ElevatorTerminal* term) {
	// server/zone/objects/tangible/terminal/elevator/ElevatorTerminal.idl():  		elevatorUp = term;
	elevatorUp = term;
}

void ElevatorTerminalImplementation::setElevatorDown(ElevatorTerminal* term) {
	// server/zone/objects/tangible/terminal/elevator/ElevatorTerminal.idl():  		elevatorDown = term;
	elevatorDown = term;
}

ElevatorTerminal* ElevatorTerminalImplementation::getElevatorUp() {
	// server/zone/objects/tangible/terminal/elevator/ElevatorTerminal.idl():  		return elevatorUp;
	return elevatorUp;
}

ElevatorTerminal* ElevatorTerminalImplementation::getElevatorDown() {
	// server/zone/objects/tangible/terminal/elevator/ElevatorTerminal.idl():  		return elevatorDown;
	return elevatorDown;
}

/*
 *	ElevatorTerminalAdapter
 */

ElevatorTerminalAdapter::ElevatorTerminalAdapter(ElevatorTerminalImplementation* obj) : TerminalAdapter(obj) {
}

Packet* ElevatorTerminalAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_FILLOBJECTMENURESPONSE__OBJECTMENURESPONSE_PLAYERCREATURE_:
		fillObjectMenuResponse((ObjectMenuResponse*) inv->getObjectParameter(), (PlayerCreature*) inv->getObjectParameter());
		break;
	case RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case RPC_ISELEVATORTERMINAL__:
		resp->insertBoolean(isElevatorTerminal());
		break;
	case RPC_SETELEVATORUP__ELEVATORTERMINAL_:
		setElevatorUp((ElevatorTerminal*) inv->getObjectParameter());
		break;
	case RPC_SETELEVATORDOWN__ELEVATORTERMINAL_:
		setElevatorDown((ElevatorTerminal*) inv->getObjectParameter());
		break;
	case RPC_GETELEVATORUP__:
		resp->insertLong(getElevatorUp()->_getObjectID());
		break;
	case RPC_GETELEVATORDOWN__:
		resp->insertLong(getElevatorDown()->_getObjectID());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ElevatorTerminalAdapter::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player) {
	((ElevatorTerminalImplementation*) impl)->fillObjectMenuResponse(menuResponse, player);
}

int ElevatorTerminalAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((ElevatorTerminalImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

bool ElevatorTerminalAdapter::isElevatorTerminal() {
	return ((ElevatorTerminalImplementation*) impl)->isElevatorTerminal();
}

void ElevatorTerminalAdapter::setElevatorUp(ElevatorTerminal* term) {
	((ElevatorTerminalImplementation*) impl)->setElevatorUp(term);
}

void ElevatorTerminalAdapter::setElevatorDown(ElevatorTerminal* term) {
	((ElevatorTerminalImplementation*) impl)->setElevatorDown(term);
}

ElevatorTerminal* ElevatorTerminalAdapter::getElevatorUp() {
	return ((ElevatorTerminalImplementation*) impl)->getElevatorUp();
}

ElevatorTerminal* ElevatorTerminalAdapter::getElevatorDown() {
	return ((ElevatorTerminalImplementation*) impl)->getElevatorDown();
}

/*
 *	ElevatorTerminalHelper
 */

ElevatorTerminalHelper* ElevatorTerminalHelper::staticInitializer = ElevatorTerminalHelper::instance();

ElevatorTerminalHelper::ElevatorTerminalHelper() {
	className = "ElevatorTerminal";

	Core::getObjectBroker()->registerClass(className, this);
}

void ElevatorTerminalHelper::finalizeHelper() {
	ElevatorTerminalHelper::finalize();
}

DistributedObject* ElevatorTerminalHelper::instantiateObject() {
	return new ElevatorTerminal(DummyConstructorParameter::instance());
}

DistributedObjectServant* ElevatorTerminalHelper::instantiateServant() {
	return new ElevatorTerminalImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ElevatorTerminalHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ElevatorTerminalAdapter((ElevatorTerminalImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

