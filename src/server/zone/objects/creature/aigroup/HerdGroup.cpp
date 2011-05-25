/*
 *	server/zone/objects/creature/aigroup/HerdGroup.cpp generated by engine3 IDL compiler 0.60
 */

#include "HerdGroup.h"


// Imported class dependencies

#include "engine/core/ManagedObject.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "engine/core/Task.h"

#include "engine/service/proto/BaseClientProxy.h"

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

#include "server/zone/managers/creature/CreatureTemplate.h"

#include "server/zone/managers/creature/DynamicSpawnGroup.h"

#include "server/zone/managers/creature/StaticSpawnGroup.h"

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

#include "server/zone/objects/creature/AiAgent.h"

#include "server/zone/objects/creature/AiObserver.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/PatrolPoint.h"

#include "server/zone/objects/creature/PatrolPointsVector.h"

#include "server/zone/objects/creature/aigroup/AiGroup.h"

#include "server/zone/objects/creature/aigroup/AiGroupObserver.h"

#include "server/zone/objects/creature/events/AiAwarenessEvent.h"

#include "server/zone/objects/creature/events/AiMoveEvent.h"

#include "server/zone/objects/creature/events/AiThinkEvent.h"

#include "server/zone/objects/creature/events/AiWaitEvent.h"

#include "server/zone/objects/creature/events/DespawnCreatureOnPlayerDissappear.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/scene/WorldCoordinates.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/objects/tangible/DamageMap.h"

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
 *	HerdGroupStub
 */

enum {RPC_ISHERDGROUP__ = 6};

HerdGroup::HerdGroup() : AiGroup(DummyConstructorParameter::instance()) {
	HerdGroupImplementation* _implementation = new HerdGroupImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

HerdGroup::HerdGroup(DummyConstructorParameter* param) : AiGroup(param) {
}

HerdGroup::~HerdGroup() {
}


bool HerdGroup::isHerdGroup() {
	HerdGroupImplementation* _implementation = (HerdGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISHERDGROUP__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isHerdGroup();
}

DistributedObjectServant* HerdGroup::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void HerdGroup::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<HerdGroupImplementation*>(servant));
}

/*
 *	HerdGroupImplementation
 */

HerdGroupImplementation::HerdGroupImplementation(DummyConstructorParameter* param) : AiGroupImplementation(param) {
	_initializeImplementation();
}


HerdGroupImplementation::~HerdGroupImplementation() {
}


void HerdGroupImplementation::finalize() {
}

void HerdGroupImplementation::_initializeImplementation() {
	_setClassHelper(HerdGroupHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void HerdGroupImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (HerdGroup*) stub;
	AiGroupImplementation::_setStub(stub);
}

DistributedObjectStub* HerdGroupImplementation::_getStub() {
	return _this;
}

HerdGroupImplementation::operator const HerdGroup*() {
	return _this;
}

Object* HerdGroupImplementation::clone() {
	return dynamic_cast<Object*>(new HerdGroupImplementation(*this));
}


void HerdGroupImplementation::lock(bool doLock) {
}

void HerdGroupImplementation::lock(ManagedObject* obj) {
}

void HerdGroupImplementation::rlock(bool doLock) {
}

void HerdGroupImplementation::wlock(bool doLock) {
}

void HerdGroupImplementation::wlock(ManagedObject* obj) {
}

void HerdGroupImplementation::unlock(bool doLock) {
}

void HerdGroupImplementation::runlock(bool doLock) {
}

void HerdGroupImplementation::_serializationHelperMethod() {
	AiGroupImplementation::_serializationHelperMethod();

	_setClassName("HerdGroup");

}

void HerdGroupImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(HerdGroupImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool HerdGroupImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (AiGroupImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void HerdGroupImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = HerdGroupImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int HerdGroupImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + AiGroupImplementation::writeObjectMembers(stream);
}

HerdGroupImplementation::HerdGroupImplementation() : AiGroupImplementation() {
	_initializeImplementation();
}

bool HerdGroupImplementation::isHerdGroup() {
	// server/zone/objects/creature/aigroup/HerdGroup.idl():  		return true;
	return true;
}

/*
 *	HerdGroupAdapter
 */

HerdGroupAdapter::HerdGroupAdapter(HerdGroupImplementation* obj) : AiGroupAdapter(obj) {
}

Packet* HerdGroupAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_ISHERDGROUP__:
		resp->insertBoolean(isHerdGroup());
		break;
	default:
		return NULL;
	}

	return resp;
}

bool HerdGroupAdapter::isHerdGroup() {
	return ((HerdGroupImplementation*) impl)->isHerdGroup();
}

/*
 *	HerdGroupHelper
 */

HerdGroupHelper* HerdGroupHelper::staticInitializer = HerdGroupHelper::instance();

HerdGroupHelper::HerdGroupHelper() {
	className = "HerdGroup";

	Core::getObjectBroker()->registerClass(className, this);
}

void HerdGroupHelper::finalizeHelper() {
	HerdGroupHelper::finalize();
}

DistributedObject* HerdGroupHelper::instantiateObject() {
	return new HerdGroup(DummyConstructorParameter::instance());
}

DistributedObjectServant* HerdGroupHelper::instantiateServant() {
	return new HerdGroupImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* HerdGroupHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new HerdGroupAdapter((HerdGroupImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

