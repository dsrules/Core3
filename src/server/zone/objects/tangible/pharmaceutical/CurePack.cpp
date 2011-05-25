/*
 *	server/zone/objects/tangible/pharmaceutical/CurePack.cpp generated by engine3 IDL compiler 0.60
 */

#include "CurePack.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"


// Imported class dependencies

#include "engine/core/ManagedObject.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "engine/core/Task.h"

#include "engine/service/DatagramServiceThread.h"

#include "engine/service/Message.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "engine/service/proto/BaseMessage.h"

#include "engine/service/proto/BasePacket.h"

#include "engine/service/proto/BasePacketHandler.h"

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

#include "server/chat/ChatManager.h"

#include "server/chat/StringIdChatParameter.h"

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
 *	CurePackStub
 */

enum {RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_,RPC_CALCULATEPOWER__CREATUREOBJECT_,RPC_ISAREA__,RPC_GETAREA__,RPC_GETSTATE__,RPC_GETEFFECTIVENESS__,RPC_ISCUREPACK__};

CurePack::CurePack() : PharmaceuticalObject(DummyConstructorParameter::instance()) {
	CurePackImplementation* _implementation = new CurePackImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

CurePack::CurePack(DummyConstructorParameter* param) : PharmaceuticalObject(param) {
}

CurePack::~CurePack() {
}


void CurePack::updateCraftingValues(ManufactureSchematic* schematic) {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->updateCraftingValues(schematic);
}

void CurePack::loadTemplateData(SharedObjectTemplate* templateData) {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

int CurePack::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
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

void CurePack::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

int CurePack::calculatePower(CreatureObject* creature) {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CALCULATEPOWER__CREATUREOBJECT_);
		method.addObjectParameter(creature);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->calculatePower(creature);
}

bool CurePack::isArea() {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISAREA__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isArea();
}

float CurePack::getArea() {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETAREA__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getArea();
}

unsigned long long CurePack::getState() {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSTATE__);

		return method.executeWithUnsignedLongReturn();
	} else
		return _implementation->getState();
}

float CurePack::getEffectiveness() {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETEFFECTIVENESS__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getEffectiveness();
}

bool CurePack::isCurePack() {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISCUREPACK__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isCurePack();
}

DistributedObjectServant* CurePack::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void CurePack::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<CurePackImplementation*>(servant));
}

/*
 *	CurePackImplementation
 */

CurePackImplementation::CurePackImplementation(DummyConstructorParameter* param) : PharmaceuticalObjectImplementation(param) {
	_initializeImplementation();
}


CurePackImplementation::~CurePackImplementation() {
}


void CurePackImplementation::finalize() {
}

void CurePackImplementation::_initializeImplementation() {
	_setClassHelper(CurePackHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void CurePackImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (CurePack*) stub;
	PharmaceuticalObjectImplementation::_setStub(stub);
}

DistributedObjectStub* CurePackImplementation::_getStub() {
	return _this;
}

CurePackImplementation::operator const CurePack*() {
	return _this;
}

Object* CurePackImplementation::clone() {
	return dynamic_cast<Object*>(new CurePackImplementation(*this));
}


void CurePackImplementation::lock(bool doLock) {
}

void CurePackImplementation::lock(ManagedObject* obj) {
}

void CurePackImplementation::rlock(bool doLock) {
}

void CurePackImplementation::wlock(bool doLock) {
}

void CurePackImplementation::wlock(ManagedObject* obj) {
}

void CurePackImplementation::unlock(bool doLock) {
}

void CurePackImplementation::runlock(bool doLock) {
}

void CurePackImplementation::_serializationHelperMethod() {
	PharmaceuticalObjectImplementation::_serializationHelperMethod();

	_setClassName("CurePack");

}

void CurePackImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(CurePackImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool CurePackImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (PharmaceuticalObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "effectiveness") {
		TypeInfo<float >::parseFromBinaryStream(&effectiveness, stream);
		return true;
	}

	if (_name == "area") {
		TypeInfo<float >::parseFromBinaryStream(&area, stream);
		return true;
	}

	if (_name == "state") {
		TypeInfo<unsigned long long >::parseFromBinaryStream(&state, stream);
		return true;
	}

	if (_name == "commandToExecute") {
		TypeInfo<String >::parseFromBinaryStream(&commandToExecute, stream);
		return true;
	}


	return false;
}

void CurePackImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = CurePackImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int CurePackImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "effectiveness";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&effectiveness, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "area";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&area, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "state";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<unsigned long long >::toBinaryStream(&state, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "commandToExecute";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<String >::toBinaryStream(&commandToExecute, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 4 + PharmaceuticalObjectImplementation::writeObjectMembers(stream);
}

CurePackImplementation::CurePackImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		setLoggingName("CurePack");
	setLoggingName("CurePack");
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		effectiveness = 0;
	effectiveness = 0;
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		area = 0;
	area = 0;
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		state = 0;
	state = 0;
}

void CurePackImplementation::updateCraftingValues(ManufactureSchematic* schematic) {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		CraftingValues craftingValues = schematic.getCraftingValues();
	CraftingValues* craftingValues = schematic->getCraftingValues();
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		effectiveness = craftingValues.getCurrentValue("power");
	effectiveness = craftingValues->getCurrentValue("power");
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		super.medicineUseRequired = craftingValues.getCurrentValue("skillmodmin");
	PharmaceuticalObjectImplementation::medicineUseRequired = craftingValues->getCurrentValue("skillmodmin");
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		setUseCount(craftingValues.getCurrentValue("charges"));
	setUseCount(craftingValues->getCurrentValue("charges"));
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  	}
	if (craftingValues->hasProperty("area")){
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			area = craftingValues.getCurrentValue("area");
	area = craftingValues->getCurrentValue("area");
}
}

void CurePackImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		super.loadTemplateData(templateData);
	PharmaceuticalObjectImplementation::loadTemplateData(templateData);
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		CurePackTemplate 
	if (!templateData->isCurePackTemplate())	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			return;
	return;
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		CurePackTemplate stimPackTemplate = (CurePackTemplate) templateData;
	CurePackTemplate* stimPackTemplate = (CurePackTemplate*) templateData;
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		effectiveness = stimPackTemplate.getEffectiveness();
	effectiveness = stimPackTemplate->getEffectiveness();
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		super.medicineUseRequired = stimPackTemplate.getMedicineUse();
	PharmaceuticalObjectImplementation::medicineUseRequired = stimPackTemplate->getMedicineUse();
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		area = stimPackTemplate.getArea();
	area = stimPackTemplate->getArea();
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		state = stimPackTemplate.getState();
	state = stimPackTemplate->getState();
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		commandToExecute = stimPackTemplate.getCommandToExecute();
	commandToExecute = stimPackTemplate->getCommandToExecute();
}

int CurePackImplementation::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		if 
	if (selectedID != 20)	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			return 1;
	return 1;
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		}
	if (player->getSkillMod("healing_ability") < PharmaceuticalObjectImplementation::medicineUseRequired){
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			player.sendSystemMessage("error_message", "insufficient_skill");
	player->sendSystemMessage("error_message", "insufficient_skill");
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			return 0;
	return 0;
}

	else {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			string command = commandToExecute + " ";
	String command = commandToExecute + " ";
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			command = command + String.valueOf(super.getObjectID());
	command = command + String::valueOf(PharmaceuticalObjectImplementation::getObjectID());
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			player.sendExecuteConsoleCommand(command);
	player->sendExecuteConsoleCommand(command);
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			return 0;
	return 0;
}
}

void CurePackImplementation::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		super.fillAttributeList(msg, object);
	PharmaceuticalObjectImplementation::fillAttributeList(msg, object);
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		string eff = "@obj_attr_n:dot_type_";
	String eff = "@obj_attr_n:dot_type_";
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		msg.insertAttribute("examine_dot_cure", eff + CreatureState.getSpecialName(state));
	msg->insertAttribute("examine_dot_cure", eff + CreatureState::getSpecialName(state));
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		msg.insertAttribute("examine_dot_cure_power", effectiveness);
	msg->insertAttribute("examine_dot_cure_power", effectiveness);
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		}
	if (isArea()){
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			msg.insertAttribute("examine_heal_area", Math.getPrecision(area, 0));
	msg->insertAttribute("examine_heal_area", Math::getPrecision(area, 0));
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			msg.insertAttribute("healing_ability", super.getMedicineUseRequired());
	msg->insertAttribute("healing_ability", PharmaceuticalObjectImplementation::getMedicineUseRequired());
}

	else {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			msg.insertAttribute("healing_ability", super.getMedicineUseRequired());
	msg->insertAttribute("healing_ability", PharmaceuticalObjectImplementation::getMedicineUseRequired());
}
}

int CurePackImplementation::calculatePower(CreatureObject* creature) {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		float modSkill = (float) creature.getSkillMod("healing_wound_treatment");
	float modSkill = (float) creature->getSkillMod("healing_wound_treatment");
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		return ((100 + modSkill) / 100 * effectiveness);
	return ((100 + modSkill) / 100 * effectiveness);
}

bool CurePackImplementation::isArea() {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		return area != 0;
	return area != 0;
}

float CurePackImplementation::getArea() {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		return area;
	return area;
}

unsigned long long CurePackImplementation::getState() {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		return state;
	return state;
}

float CurePackImplementation::getEffectiveness() {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		return effectiveness;
	return effectiveness;
}

bool CurePackImplementation::isCurePack() {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		return true;
	return true;
}

/*
 *	CurePackAdapter
 */

CurePackAdapter::CurePackAdapter(CurePackImplementation* obj) : PharmaceuticalObjectAdapter(obj) {
}

Packet* CurePackAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case RPC_CALCULATEPOWER__CREATUREOBJECT_:
		resp->insertSignedInt(calculatePower((CreatureObject*) inv->getObjectParameter()));
		break;
	case RPC_ISAREA__:
		resp->insertBoolean(isArea());
		break;
	case RPC_GETAREA__:
		resp->insertFloat(getArea());
		break;
	case RPC_GETSTATE__:
		resp->insertLong(getState());
		break;
	case RPC_GETEFFECTIVENESS__:
		resp->insertFloat(getEffectiveness());
		break;
	case RPC_ISCUREPACK__:
		resp->insertBoolean(isCurePack());
		break;
	default:
		return NULL;
	}

	return resp;
}

int CurePackAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((CurePackImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

int CurePackAdapter::calculatePower(CreatureObject* creature) {
	return ((CurePackImplementation*) impl)->calculatePower(creature);
}

bool CurePackAdapter::isArea() {
	return ((CurePackImplementation*) impl)->isArea();
}

float CurePackAdapter::getArea() {
	return ((CurePackImplementation*) impl)->getArea();
}

unsigned long long CurePackAdapter::getState() {
	return ((CurePackImplementation*) impl)->getState();
}

float CurePackAdapter::getEffectiveness() {
	return ((CurePackImplementation*) impl)->getEffectiveness();
}

bool CurePackAdapter::isCurePack() {
	return ((CurePackImplementation*) impl)->isCurePack();
}

/*
 *	CurePackHelper
 */

CurePackHelper* CurePackHelper::staticInitializer = CurePackHelper::instance();

CurePackHelper::CurePackHelper() {
	className = "CurePack";

	Core::getObjectBroker()->registerClass(className, this);
}

void CurePackHelper::finalizeHelper() {
	CurePackHelper::finalize();
}

DistributedObject* CurePackHelper::instantiateObject() {
	return new CurePack(DummyConstructorParameter::instance());
}

DistributedObjectServant* CurePackHelper::instantiateServant() {
	return new CurePackImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CurePackHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CurePackAdapter((CurePackImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

