/*
 *	server/zone/managers/radial/RadialManager.cpp generated by engine3 IDL compiler 0.60
 */

#include "RadialManager.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/scene/SceneObject.h"


// Imported class dependencies

#include "engine/core/ManagedObject.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "engine/core/Task.h"

#include "engine/service/DatagramServiceThread.h"

#include "engine/service/Message.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "engine/service/proto/BasePacket.h"

#include "engine/service/proto/BasePacketHandler.h"

#include "engine/stm/TransactionalReference.h"

#include "engine/util/Facade.h"

#include "engine/util/u3d/Coordinate.h"

#include "engine/util/u3d/QuadTree.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "engine/util/u3d/Quaternion.h"

#include "server/chat/ChatManager.h"

#include "server/chat/room/ChatRoom.h"

#include "server/login/account/Account.h"

#include "server/login/account/AccountManager.h"

#include "server/zone/Zone.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/ZoneHandler.h"

#include "server/zone/ZonePacketHandler.h"

#include "server/zone/ZoneProcessServer.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/managers/auction/AuctionManager.h"

#include "server/zone/managers/city/CityManager.h"

#include "server/zone/managers/crafting/CraftingManager.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/zone/managers/creature/CreatureTemplateManager.h"

#include "server/zone/managers/guild/GuildManager.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/managers/loot/LootManager.h"

#include "server/zone/managers/minigames/FishingManager.h"

#include "server/zone/managers/minigames/ForageManager.h"

#include "server/zone/managers/minigames/GamblingManager.h"

#include "server/zone/managers/mission/MissionManager.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "server/zone/managers/planet/PlanetManager.h"

#include "server/zone/managers/player/PlayerManager.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "server/zone/managers/radial/RadialManager.h"

#include "server/zone/managers/resource/ResourceManager.h"

#include "server/zone/managers/stringid/StringIdManager.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "server/zone/objects/cell/CellObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "system/io/ObjectInputStream.h"

#include "system/io/ObjectOutputStream.h"

#include "system/lang/Exception.h"

#include "system/lang/Time.h"

#include "system/net/Packet.h"

#include "system/net/Socket.h"

#include "system/net/SocketAddress.h"

#include "system/thread/atomic/AtomicInteger.h"

#include "system/util/SortedVector.h"

#include "system/util/Vector.h"

#include "system/util/VectorMap.h"

/*
 *	RadialManagerStub
 */

enum {RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_LONG_ = 6,RPC_HANDLEOBJECTMENUREQUEST__PLAYERCREATURE_OBJECTMENURESPONSE_LONG_};

RadialManager::RadialManager(ZoneServer* server) : ManagedObject(DummyConstructorParameter::instance()) {
	RadialManagerImplementation* _implementation = new RadialManagerImplementation(server);
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

RadialManager::RadialManager(DummyConstructorParameter* param) : ManagedObject(param) {
}

RadialManager::~RadialManager() {
}


void RadialManager::handleObjectMenuSelect(PlayerCreature* player, byte selectID, unsigned long long objectID) {
	RadialManagerImplementation* _implementation = (RadialManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_LONG_);
		method.addObjectParameter(player);
		method.addByteParameter(selectID);
		method.addUnsignedLongParameter(objectID);

		method.executeWithVoidReturn();
	} else
		_implementation->handleObjectMenuSelect(player, selectID, objectID);
}

void RadialManager::handleObjectMenuRequest(PlayerCreature* player, ObjectMenuResponse* defaultMenuResponse, unsigned long long objectID) {
	RadialManagerImplementation* _implementation = (RadialManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HANDLEOBJECTMENUREQUEST__PLAYERCREATURE_OBJECTMENURESPONSE_LONG_);
		method.addObjectParameter(player);
		method.addObjectParameter(defaultMenuResponse);
		method.addUnsignedLongParameter(objectID);

		method.executeWithVoidReturn();
	} else
		_implementation->handleObjectMenuRequest(player, defaultMenuResponse, objectID);
}

DistributedObjectServant* RadialManager::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void RadialManager::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<RadialManagerImplementation*>(servant));
}

/*
 *	RadialManagerImplementation
 */

RadialManagerImplementation::RadialManagerImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


RadialManagerImplementation::~RadialManagerImplementation() {
}


void RadialManagerImplementation::finalize() {
}

void RadialManagerImplementation::_initializeImplementation() {
	_setClassHelper(RadialManagerHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void RadialManagerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (RadialManager*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* RadialManagerImplementation::_getStub() {
	return _this;
}

RadialManagerImplementation::operator const RadialManager*() {
	return _this;
}

Object* RadialManagerImplementation::clone() {
	return dynamic_cast<Object*>(new RadialManagerImplementation(*this));
}


void RadialManagerImplementation::lock(bool doLock) {
}

void RadialManagerImplementation::lock(ManagedObject* obj) {
}

void RadialManagerImplementation::rlock(bool doLock) {
}

void RadialManagerImplementation::wlock(bool doLock) {
}

void RadialManagerImplementation::wlock(ManagedObject* obj) {
}

void RadialManagerImplementation::unlock(bool doLock) {
}

void RadialManagerImplementation::runlock(bool doLock) {
}

void RadialManagerImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("RadialManager");

}

void RadialManagerImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(RadialManagerImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool RadialManagerImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "zoneServer") {
		TypeInfo<ManagedWeakReference<ZoneServer* > >::parseFromBinaryStream(&zoneServer, stream);
		return true;
	}


	return false;
}

void RadialManagerImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = RadialManagerImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int RadialManagerImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "zoneServer";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedWeakReference<ZoneServer* > >::toBinaryStream(&zoneServer, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + ManagedObjectImplementation::writeObjectMembers(stream);
}

/*
 *	RadialManagerAdapter
 */

RadialManagerAdapter::RadialManagerAdapter(RadialManagerImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* RadialManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_LONG_:
		handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter(), inv->getUnsignedLongParameter());
		break;
	case RPC_HANDLEOBJECTMENUREQUEST__PLAYERCREATURE_OBJECTMENURESPONSE_LONG_:
		handleObjectMenuRequest((PlayerCreature*) inv->getObjectParameter(), (ObjectMenuResponse*) inv->getObjectParameter(), inv->getUnsignedLongParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void RadialManagerAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectID, unsigned long long objectID) {
	((RadialManagerImplementation*) impl)->handleObjectMenuSelect(player, selectID, objectID);
}

void RadialManagerAdapter::handleObjectMenuRequest(PlayerCreature* player, ObjectMenuResponse* defaultMenuResponse, unsigned long long objectID) {
	((RadialManagerImplementation*) impl)->handleObjectMenuRequest(player, defaultMenuResponse, objectID);
}

/*
 *	RadialManagerHelper
 */

RadialManagerHelper* RadialManagerHelper::staticInitializer = RadialManagerHelper::instance();

RadialManagerHelper::RadialManagerHelper() {
	className = "RadialManager";

	Core::getObjectBroker()->registerClass(className, this);
}

void RadialManagerHelper::finalizeHelper() {
	RadialManagerHelper::finalize();
}

DistributedObject* RadialManagerHelper::instantiateObject() {
	return new RadialManager(DummyConstructorParameter::instance());
}

DistributedObjectServant* RadialManagerHelper::instantiateServant() {
	return new RadialManagerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* RadialManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new RadialManagerAdapter((RadialManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

