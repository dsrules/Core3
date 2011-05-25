/*
 *	server/zone/objects/tangible/terminal/cloning/CloningTerminal.cpp generated by engine3 IDL compiler 0.60
 */

#include "CloningTerminal.h"

#include "server/zone/objects/tangible/TangibleObject.h"

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
 *	CloningTerminalStub
 */

enum {RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_ = 6};

CloningTerminal::CloningTerminal() : Terminal(DummyConstructorParameter::instance()) {
	CloningTerminalImplementation* _implementation = new CloningTerminalImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

CloningTerminal::CloningTerminal(DummyConstructorParameter* param) : Terminal(param) {
}

CloningTerminal::~CloningTerminal() {
}


int CloningTerminal::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	CloningTerminalImplementation* _implementation = (CloningTerminalImplementation*) _getImplementation();
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

DistributedObjectServant* CloningTerminal::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void CloningTerminal::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<CloningTerminalImplementation*>(servant));
}

/*
 *	CloningTerminalImplementation
 */

CloningTerminalImplementation::CloningTerminalImplementation(DummyConstructorParameter* param) : TerminalImplementation(param) {
	_initializeImplementation();
}


CloningTerminalImplementation::~CloningTerminalImplementation() {
}


void CloningTerminalImplementation::finalize() {
}

void CloningTerminalImplementation::_initializeImplementation() {
	_setClassHelper(CloningTerminalHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void CloningTerminalImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (CloningTerminal*) stub;
	TerminalImplementation::_setStub(stub);
}

DistributedObjectStub* CloningTerminalImplementation::_getStub() {
	return _this;
}

CloningTerminalImplementation::operator const CloningTerminal*() {
	return _this;
}

Object* CloningTerminalImplementation::clone() {
	return dynamic_cast<Object*>(new CloningTerminalImplementation(*this));
}


void CloningTerminalImplementation::lock(bool doLock) {
}

void CloningTerminalImplementation::lock(ManagedObject* obj) {
}

void CloningTerminalImplementation::rlock(bool doLock) {
}

void CloningTerminalImplementation::wlock(bool doLock) {
}

void CloningTerminalImplementation::wlock(ManagedObject* obj) {
}

void CloningTerminalImplementation::unlock(bool doLock) {
}

void CloningTerminalImplementation::runlock(bool doLock) {
}

void CloningTerminalImplementation::_serializationHelperMethod() {
	TerminalImplementation::_serializationHelperMethod();

	_setClassName("CloningTerminal");

}

void CloningTerminalImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(CloningTerminalImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool CloningTerminalImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TerminalImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void CloningTerminalImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = CloningTerminalImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int CloningTerminalImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + TerminalImplementation::writeObjectMembers(stream);
}

CloningTerminalImplementation::CloningTerminalImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/terminal/cloning/CloningTerminal.idl():  		Logger.setLoggingName("Cloning Terminal");
	Logger::setLoggingName("Cloning Terminal");
}

/*
 *	CloningTerminalAdapter
 */

CloningTerminalAdapter::CloningTerminalAdapter(CloningTerminalImplementation* obj) : TerminalAdapter(obj) {
}

Packet* CloningTerminalAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

int CloningTerminalAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((CloningTerminalImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

/*
 *	CloningTerminalHelper
 */

CloningTerminalHelper* CloningTerminalHelper::staticInitializer = CloningTerminalHelper::instance();

CloningTerminalHelper::CloningTerminalHelper() {
	className = "CloningTerminal";

	Core::getObjectBroker()->registerClass(className, this);
}

void CloningTerminalHelper::finalizeHelper() {
	CloningTerminalHelper::finalize();
}

DistributedObject* CloningTerminalHelper::instantiateObject() {
	return new CloningTerminal(DummyConstructorParameter::instance());
}

DistributedObjectServant* CloningTerminalHelper::instantiateServant() {
	return new CloningTerminalImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CloningTerminalHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CloningTerminalAdapter((CloningTerminalImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

