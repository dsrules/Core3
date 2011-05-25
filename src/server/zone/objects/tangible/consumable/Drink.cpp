/*
 *	server/zone/objects/tangible/consumable/Drink.cpp generated by engine3 IDL compiler 0.60
 */

#include "Drink.h"

#include "server/zone/objects/scene/SceneObject.h"

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

#include "server/zone/objects/creature/buffs/BuffDurationEvent.h"

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
 *	DrinkStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_INITIALIZEPRIVATEDATA__};

Drink::Drink() : Consumable(DummyConstructorParameter::instance()) {
	DrinkImplementation* _implementation = new DrinkImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

Drink::Drink(DummyConstructorParameter* param) : Consumable(param) {
}

Drink::~Drink() {
}


void Drink::initializeTransientMembers() {
	DrinkImplementation* _implementation = (DrinkImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void Drink::initializePrivateData() {
	DrinkImplementation* _implementation = (DrinkImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZEPRIVATEDATA__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializePrivateData();
}

DistributedObjectServant* Drink::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void Drink::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<DrinkImplementation*>(servant));
}

/*
 *	DrinkImplementation
 */

DrinkImplementation::DrinkImplementation(DummyConstructorParameter* param) : ConsumableImplementation(param) {
	_initializeImplementation();
}


DrinkImplementation::~DrinkImplementation() {
}


void DrinkImplementation::finalize() {
}

void DrinkImplementation::_initializeImplementation() {
	_setClassHelper(DrinkHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void DrinkImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Drink*) stub;
	ConsumableImplementation::_setStub(stub);
}

DistributedObjectStub* DrinkImplementation::_getStub() {
	return _this;
}

DrinkImplementation::operator const Drink*() {
	return _this;
}

Object* DrinkImplementation::clone() {
	return dynamic_cast<Object*>(new DrinkImplementation(*this));
}


void DrinkImplementation::lock(bool doLock) {
}

void DrinkImplementation::lock(ManagedObject* obj) {
}

void DrinkImplementation::rlock(bool doLock) {
}

void DrinkImplementation::wlock(bool doLock) {
}

void DrinkImplementation::wlock(ManagedObject* obj) {
}

void DrinkImplementation::unlock(bool doLock) {
}

void DrinkImplementation::runlock(bool doLock) {
}

void DrinkImplementation::_serializationHelperMethod() {
	ConsumableImplementation::_serializationHelperMethod();

	_setClassName("Drink");

}

void DrinkImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(DrinkImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool DrinkImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ConsumableImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void DrinkImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = DrinkImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int DrinkImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + ConsumableImplementation::writeObjectMembers(stream);
}

DrinkImplementation::DrinkImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/consumable/Drink.idl():  		Logger.setLoggingName("Drink");
	Logger::setLoggingName("Drink");
	// server/zone/objects/tangible/consumable/Drink.idl():  		initializePrivateData();
	initializePrivateData();
}

void DrinkImplementation::initializeTransientMembers() {
	// server/zone/objects/tangible/consumable/Drink.idl():  		super.initializeTransientMembers();
	ConsumableImplementation::initializeTransientMembers();
	// server/zone/objects/tangible/consumable/Drink.idl():  		Logger.setLoggingName("Drink");
	Logger::setLoggingName("Drink");
}

void DrinkImplementation::initializePrivateData() {
	// server/zone/objects/tangible/consumable/Drink.idl():  		super.consumableType = super.DRINK;
	ConsumableImplementation::consumableType = ConsumableImplementation::DRINK;
}

/*
 *	DrinkAdapter
 */

DrinkAdapter::DrinkAdapter(DrinkImplementation* obj) : ConsumableAdapter(obj) {
}

Packet* DrinkAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_INITIALIZEPRIVATEDATA__:
		initializePrivateData();
		break;
	default:
		return NULL;
	}

	return resp;
}

void DrinkAdapter::initializeTransientMembers() {
	((DrinkImplementation*) impl)->initializeTransientMembers();
}

void DrinkAdapter::initializePrivateData() {
	((DrinkImplementation*) impl)->initializePrivateData();
}

/*
 *	DrinkHelper
 */

DrinkHelper* DrinkHelper::staticInitializer = DrinkHelper::instance();

DrinkHelper::DrinkHelper() {
	className = "Drink";

	Core::getObjectBroker()->registerClass(className, this);
}

void DrinkHelper::finalizeHelper() {
	DrinkHelper::finalize();
}

DistributedObject* DrinkHelper::instantiateObject() {
	return new Drink(DummyConstructorParameter::instance());
}

DistributedObjectServant* DrinkHelper::instantiateServant() {
	return new DrinkImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DrinkHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DrinkAdapter((DrinkImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

