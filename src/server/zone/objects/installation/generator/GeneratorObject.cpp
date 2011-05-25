/*
 *	server/zone/objects/installation/generator/GeneratorObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "GeneratorObject.h"

#include "server/zone/objects/area/ActiveArea.h"


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

#include "server/zone/objects/installation/HopperList.h"

#include "server/zone/objects/installation/SyncrhonizedUiListenInstallationTask.h"

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

#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

#include "server/zone/objects/resource/ResourceContainer.h"

#include "server/zone/objects/resource/ResourceSpawn.h"

#include "server/zone/objects/resource/SpawnMap.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/objects/structure/StructurePermissionList.h"

#include "server/zone/objects/structure/events/StructureMaintenanceTask.h"

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
 *	GeneratorObjectStub
 */

enum {RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_,RPC_SYNCHRONIZEDUILISTEN__SCENEOBJECT_INT_,RPC_SYNCHRONIZEDUISTOPLISTEN__SCENEOBJECT_INT_,RPC_ISGENERATOROBJECT__};

GeneratorObject::GeneratorObject() : InstallationObject(DummyConstructorParameter::instance()) {
	GeneratorObjectImplementation* _implementation = new GeneratorObjectImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

GeneratorObject::GeneratorObject(DummyConstructorParameter* param) : InstallationObject(param) {
}

GeneratorObject::~GeneratorObject() {
}


void GeneratorObject::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player) {
	GeneratorObjectImplementation* _implementation = (GeneratorObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillObjectMenuResponse(menuResponse, player);
}

int GeneratorObject::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	GeneratorObjectImplementation* _implementation = (GeneratorObjectImplementation*) _getImplementation();
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

void GeneratorObject::synchronizedUIListen(SceneObject* player, int value) {
	GeneratorObjectImplementation* _implementation = (GeneratorObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SYNCHRONIZEDUILISTEN__SCENEOBJECT_INT_);
		method.addObjectParameter(player);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		_implementation->synchronizedUIListen(player, value);
}

void GeneratorObject::synchronizedUIStopListen(SceneObject* player, int value) {
	GeneratorObjectImplementation* _implementation = (GeneratorObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SYNCHRONIZEDUISTOPLISTEN__SCENEOBJECT_INT_);
		method.addObjectParameter(player);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		_implementation->synchronizedUIStopListen(player, value);
}

bool GeneratorObject::isGeneratorObject() {
	GeneratorObjectImplementation* _implementation = (GeneratorObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISGENERATOROBJECT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isGeneratorObject();
}

DistributedObjectServant* GeneratorObject::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void GeneratorObject::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<GeneratorObjectImplementation*>(servant));
}

/*
 *	GeneratorObjectImplementation
 */

GeneratorObjectImplementation::GeneratorObjectImplementation(DummyConstructorParameter* param) : InstallationObjectImplementation(param) {
	_initializeImplementation();
}


GeneratorObjectImplementation::~GeneratorObjectImplementation() {
}


void GeneratorObjectImplementation::finalize() {
}

void GeneratorObjectImplementation::_initializeImplementation() {
	_setClassHelper(GeneratorObjectHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void GeneratorObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (GeneratorObject*) stub;
	InstallationObjectImplementation::_setStub(stub);
}

DistributedObjectStub* GeneratorObjectImplementation::_getStub() {
	return _this;
}

GeneratorObjectImplementation::operator const GeneratorObject*() {
	return _this;
}

Object* GeneratorObjectImplementation::clone() {
	return dynamic_cast<Object*>(new GeneratorObjectImplementation(*this));
}


void GeneratorObjectImplementation::lock(bool doLock) {
}

void GeneratorObjectImplementation::lock(ManagedObject* obj) {
}

void GeneratorObjectImplementation::rlock(bool doLock) {
}

void GeneratorObjectImplementation::wlock(bool doLock) {
}

void GeneratorObjectImplementation::wlock(ManagedObject* obj) {
}

void GeneratorObjectImplementation::unlock(bool doLock) {
}

void GeneratorObjectImplementation::runlock(bool doLock) {
}

void GeneratorObjectImplementation::_serializationHelperMethod() {
	InstallationObjectImplementation::_serializationHelperMethod();

	_setClassName("GeneratorObject");

}

void GeneratorObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(GeneratorObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool GeneratorObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (InstallationObjectImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void GeneratorObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = GeneratorObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int GeneratorObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + InstallationObjectImplementation::writeObjectMembers(stream);
}

GeneratorObjectImplementation::GeneratorObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/installation/generator/GeneratorObject.idl():  		Logger.setLoggingName("GeneratorObject");
	Logger::setLoggingName("GeneratorObject");
}

bool GeneratorObjectImplementation::isGeneratorObject() {
	// server/zone/objects/installation/generator/GeneratorObject.idl():  		return true;
	return true;
}

/*
 *	GeneratorObjectAdapter
 */

GeneratorObjectAdapter::GeneratorObjectAdapter(GeneratorObjectImplementation* obj) : InstallationObjectAdapter(obj) {
}

Packet* GeneratorObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case RPC_SYNCHRONIZEDUILISTEN__SCENEOBJECT_INT_:
		synchronizedUIListen((SceneObject*) inv->getObjectParameter(), inv->getSignedIntParameter());
		break;
	case RPC_SYNCHRONIZEDUISTOPLISTEN__SCENEOBJECT_INT_:
		synchronizedUIStopListen((SceneObject*) inv->getObjectParameter(), inv->getSignedIntParameter());
		break;
	case RPC_ISGENERATOROBJECT__:
		resp->insertBoolean(isGeneratorObject());
		break;
	default:
		return NULL;
	}

	return resp;
}

int GeneratorObjectAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((GeneratorObjectImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

void GeneratorObjectAdapter::synchronizedUIListen(SceneObject* player, int value) {
	((GeneratorObjectImplementation*) impl)->synchronizedUIListen(player, value);
}

void GeneratorObjectAdapter::synchronizedUIStopListen(SceneObject* player, int value) {
	((GeneratorObjectImplementation*) impl)->synchronizedUIStopListen(player, value);
}

bool GeneratorObjectAdapter::isGeneratorObject() {
	return ((GeneratorObjectImplementation*) impl)->isGeneratorObject();
}

/*
 *	GeneratorObjectHelper
 */

GeneratorObjectHelper* GeneratorObjectHelper::staticInitializer = GeneratorObjectHelper::instance();

GeneratorObjectHelper::GeneratorObjectHelper() {
	className = "GeneratorObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void GeneratorObjectHelper::finalizeHelper() {
	GeneratorObjectHelper::finalize();
}

DistributedObject* GeneratorObjectHelper::instantiateObject() {
	return new GeneratorObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* GeneratorObjectHelper::instantiateServant() {
	return new GeneratorObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* GeneratorObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new GeneratorObjectAdapter((GeneratorObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

