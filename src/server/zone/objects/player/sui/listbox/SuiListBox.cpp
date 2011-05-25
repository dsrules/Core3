/*
 *	server/zone/objects/player/sui/listbox/SuiListBox.cpp generated by engine3 IDL compiler 0.60
 */

#include "SuiListBox.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"


// Imported class dependencies

#include "engine/core/ManagedObject.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "engine/core/Task.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "engine/service/proto/BasePacket.h"

#include "engine/stm/TransactionalReference.h"

#include "engine/util/Facade.h"

#include "engine/util/u3d/Coordinate.h"

#include "engine/util/u3d/QuadTree.h"

#include "engine/util/u3d/QuadTreeEntry.h"

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

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/player/sui/SuiCallback.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/packets/ui/SuiCreatePageMessage.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "system/io/ObjectInputStream.h"

#include "system/io/ObjectOutputStream.h"

#include "system/lang/Time.h"

#include "system/util/SortedVector.h"

#include "system/util/Vector.h"

#include "system/util/VectorMap.h"

/*
 *	SuiListBoxStub
 */

enum {RPC_INIT__ = 6,RPC_ADDMENUITEM__STRING_LONG_,RPC_GETMENUITEMNAME__INT_,RPC_REMOVEALLMENUITEMS__,RPC_GETMENUOBJECTID__INT_,RPC_GETMENUSIZE__,RPC_GENERATEMESSAGE__,RPC_SETNEXTBOX__INT_,RPC_SETPREVIOUSBOX__INT_,RPC_GETNEXTBOX__,RPC_GETPREVIOUSBOX__,RPC_ISLISTBOX__};

SuiListBox::SuiListBox(PlayerCreature* player, unsigned int windowType, unsigned int listBoxType) : SuiBox(DummyConstructorParameter::instance()) {
	SuiListBoxImplementation* _implementation = new SuiListBoxImplementation(player, windowType, listBoxType);
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

SuiListBox::SuiListBox(DummyConstructorParameter* param) : SuiBox(param) {
}

SuiListBox::~SuiListBox() {
}


void SuiListBox::init() {
	SuiListBoxImplementation* _implementation = (SuiListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INIT__);

		method.executeWithVoidReturn();
	} else
		_implementation->init();
}

void SuiListBox::addMenuItem(const String& name, unsigned long long objectID) {
	SuiListBoxImplementation* _implementation = (SuiListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ADDMENUITEM__STRING_LONG_);
		method.addAsciiParameter(name);
		method.addUnsignedLongParameter(objectID);

		method.executeWithVoidReturn();
	} else
		_implementation->addMenuItem(name, objectID);
}

String SuiListBox::getMenuItemName(int index) {
	SuiListBoxImplementation* _implementation = (SuiListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETMENUITEMNAME__INT_);
		method.addSignedIntParameter(index);

		method.executeWithAsciiReturn(_return_getMenuItemName);
		return _return_getMenuItemName;
	} else
		return _implementation->getMenuItemName(index);
}

void SuiListBox::removeAllMenuItems() {
	SuiListBoxImplementation* _implementation = (SuiListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_REMOVEALLMENUITEMS__);

		method.executeWithVoidReturn();
	} else
		_implementation->removeAllMenuItems();
}

unsigned long long SuiListBox::getMenuObjectID(unsigned int idx) {
	SuiListBoxImplementation* _implementation = (SuiListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETMENUOBJECTID__INT_);
		method.addUnsignedIntParameter(idx);

		return method.executeWithUnsignedLongReturn();
	} else
		return _implementation->getMenuObjectID(idx);
}

int SuiListBox::getMenuSize() {
	SuiListBoxImplementation* _implementation = (SuiListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETMENUSIZE__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getMenuSize();
}

BaseMessage* SuiListBox::generateMessage() {
	SuiListBoxImplementation* _implementation = (SuiListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GENERATEMESSAGE__);

		return (BaseMessage*) method.executeWithObjectReturn();
	} else
		return _implementation->generateMessage();
}

void SuiListBox::setNextBox(unsigned int boxID) {
	SuiListBoxImplementation* _implementation = (SuiListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETNEXTBOX__INT_);
		method.addUnsignedIntParameter(boxID);

		method.executeWithVoidReturn();
	} else
		_implementation->setNextBox(boxID);
}

void SuiListBox::setPreviousBox(unsigned int boxID) {
	SuiListBoxImplementation* _implementation = (SuiListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETPREVIOUSBOX__INT_);
		method.addUnsignedIntParameter(boxID);

		method.executeWithVoidReturn();
	} else
		_implementation->setPreviousBox(boxID);
}

unsigned long long SuiListBox::getNextBox() {
	SuiListBoxImplementation* _implementation = (SuiListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETNEXTBOX__);

		return method.executeWithUnsignedLongReturn();
	} else
		return _implementation->getNextBox();
}

unsigned long long SuiListBox::getPreviousBox() {
	SuiListBoxImplementation* _implementation = (SuiListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETPREVIOUSBOX__);

		return method.executeWithUnsignedLongReturn();
	} else
		return _implementation->getPreviousBox();
}

bool SuiListBox::isListBox() {
	SuiListBoxImplementation* _implementation = (SuiListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISLISTBOX__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isListBox();
}

DistributedObjectServant* SuiListBox::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void SuiListBox::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<SuiListBoxImplementation*>(servant));
}

/*
 *	SuiListBoxImplementation
 */

SuiListBoxImplementation::SuiListBoxImplementation(DummyConstructorParameter* param) : SuiBoxImplementation(param) {
	_initializeImplementation();
}


SuiListBoxImplementation::~SuiListBoxImplementation() {
}


void SuiListBoxImplementation::finalize() {
}

void SuiListBoxImplementation::_initializeImplementation() {
	_setClassHelper(SuiListBoxHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void SuiListBoxImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (SuiListBox*) stub;
	SuiBoxImplementation::_setStub(stub);
}

DistributedObjectStub* SuiListBoxImplementation::_getStub() {
	return _this;
}

SuiListBoxImplementation::operator const SuiListBox*() {
	return _this;
}

Object* SuiListBoxImplementation::clone() {
	return dynamic_cast<Object*>(new SuiListBoxImplementation(*this));
}


void SuiListBoxImplementation::lock(bool doLock) {
}

void SuiListBoxImplementation::lock(ManagedObject* obj) {
}

void SuiListBoxImplementation::rlock(bool doLock) {
}

void SuiListBoxImplementation::wlock(bool doLock) {
}

void SuiListBoxImplementation::wlock(ManagedObject* obj) {
}

void SuiListBoxImplementation::unlock(bool doLock) {
}

void SuiListBoxImplementation::runlock(bool doLock) {
}

void SuiListBoxImplementation::_serializationHelperMethod() {
	SuiBoxImplementation::_serializationHelperMethod();

	_setClassName("SuiListBox");

}

void SuiListBoxImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(SuiListBoxImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool SuiListBoxImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (SuiBoxImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "menuItems") {
		TypeInfo<Vector<ManagedReference<SuiListBoxMenuItem* > > >::parseFromBinaryStream(&menuItems, stream);
		return true;
	}

	if (_name == "type") {
		TypeInfo<int >::parseFromBinaryStream(&type, stream);
		return true;
	}

	if (_name == "next") {
		TypeInfo<unsigned long long >::parseFromBinaryStream(&next, stream);
		return true;
	}

	if (_name == "previous") {
		TypeInfo<unsigned long long >::parseFromBinaryStream(&previous, stream);
		return true;
	}


	return false;
}

void SuiListBoxImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = SuiListBoxImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int SuiListBoxImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "menuItems";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<Vector<ManagedReference<SuiListBoxMenuItem* > > >::toBinaryStream(&menuItems, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "type";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&type, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "next";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<unsigned long long >::toBinaryStream(&next, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "previous";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<unsigned long long >::toBinaryStream(&previous, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 4 + SuiBoxImplementation::writeObjectMembers(stream);
}

SuiListBoxImplementation::SuiListBoxImplementation(PlayerCreature* player, unsigned int windowType, unsigned int listBoxType) : SuiBoxImplementation(player, windowType, SuiBox::LISTBOX) {
	_initializeImplementation();
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		type = listBoxType;
	type = listBoxType;
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		init();
	init();
}

void SuiListBoxImplementation::init() {
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		next = 0;
	next = 0;
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		previous = 0;
	previous = 0;
}

void SuiListBoxImplementation::addMenuItem(const String& name, unsigned long long objectID) {
	ManagedReference<SuiListBoxMenuItem*> _ref0;
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		SuiListBoxMenuItem item = new SuiListBoxMenuItem(name, objectID);
	SuiListBoxMenuItem* item = _ref0 = new SuiListBoxMenuItem(name, objectID);
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		menuItems.add(item);
	(&menuItems)->add(item);
}

String SuiListBoxImplementation::getMenuItemName(int index) {
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		SuiListBoxMenuItem menuItem = menuItems.get(index);
	SuiListBoxMenuItem* menuItem = (&menuItems)->get(index);
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		return menuItem.getOptionName();
	return menuItem->getOptionName();
}

void SuiListBoxImplementation::removeAllMenuItems() {
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		menuItems.removeAll();
	(&menuItems)->removeAll();
}

unsigned long long SuiListBoxImplementation::getMenuObjectID(unsigned int idx) {
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		return 
	if (idx < (&menuItems)->size()){
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  			SuiListBoxMenuItem menuItem = menuItems.get(idx);
	SuiListBoxMenuItem* menuItem = (&menuItems)->get(idx);
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		}
	if (menuItem != NULL)	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  				return menuItem.getObjectID();
	return menuItem->getObjectID();
}
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		return 0;
	return 0;
}

int SuiListBoxImplementation::getMenuSize() {
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		return menuItems.size();
	return (&menuItems)->size();
}

void SuiListBoxImplementation::setNextBox(unsigned int boxID) {
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		next = boxID;
	next = boxID;
}

void SuiListBoxImplementation::setPreviousBox(unsigned int boxID) {
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		previous = boxID;
	previous = boxID;
}

unsigned long long SuiListBoxImplementation::getNextBox() {
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		return next;
	return next;
}

unsigned long long SuiListBoxImplementation::getPreviousBox() {
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		return previous;
	return previous;
}

bool SuiListBoxImplementation::isListBox() {
	// server/zone/objects/player/sui/listbox/SuiListBox.idl():  		return true;
	return true;
}

/*
 *	SuiListBoxAdapter
 */

SuiListBoxAdapter::SuiListBoxAdapter(SuiListBoxImplementation* obj) : SuiBoxAdapter(obj) {
}

Packet* SuiListBoxAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INIT__:
		init();
		break;
	case RPC_ADDMENUITEM__STRING_LONG_:
		addMenuItem(inv->getAsciiParameter(_param0_addMenuItem__String_long_), inv->getUnsignedLongParameter());
		break;
	case RPC_GETMENUITEMNAME__INT_:
		resp->insertAscii(getMenuItemName(inv->getSignedIntParameter()));
		break;
	case RPC_REMOVEALLMENUITEMS__:
		removeAllMenuItems();
		break;
	case RPC_GETMENUOBJECTID__INT_:
		resp->insertLong(getMenuObjectID(inv->getUnsignedIntParameter()));
		break;
	case RPC_GETMENUSIZE__:
		resp->insertSignedInt(getMenuSize());
		break;
	case RPC_GENERATEMESSAGE__:
		resp->insertLong(generateMessage()->_getObjectID());
		break;
	case RPC_SETNEXTBOX__INT_:
		setNextBox(inv->getUnsignedIntParameter());
		break;
	case RPC_SETPREVIOUSBOX__INT_:
		setPreviousBox(inv->getUnsignedIntParameter());
		break;
	case RPC_GETNEXTBOX__:
		resp->insertLong(getNextBox());
		break;
	case RPC_GETPREVIOUSBOX__:
		resp->insertLong(getPreviousBox());
		break;
	case RPC_ISLISTBOX__:
		resp->insertBoolean(isListBox());
		break;
	default:
		return NULL;
	}

	return resp;
}

void SuiListBoxAdapter::init() {
	((SuiListBoxImplementation*) impl)->init();
}

void SuiListBoxAdapter::addMenuItem(const String& name, unsigned long long objectID) {
	((SuiListBoxImplementation*) impl)->addMenuItem(name, objectID);
}

String SuiListBoxAdapter::getMenuItemName(int index) {
	return ((SuiListBoxImplementation*) impl)->getMenuItemName(index);
}

void SuiListBoxAdapter::removeAllMenuItems() {
	((SuiListBoxImplementation*) impl)->removeAllMenuItems();
}

unsigned long long SuiListBoxAdapter::getMenuObjectID(unsigned int idx) {
	return ((SuiListBoxImplementation*) impl)->getMenuObjectID(idx);
}

int SuiListBoxAdapter::getMenuSize() {
	return ((SuiListBoxImplementation*) impl)->getMenuSize();
}

BaseMessage* SuiListBoxAdapter::generateMessage() {
	return ((SuiListBoxImplementation*) impl)->generateMessage();
}

void SuiListBoxAdapter::setNextBox(unsigned int boxID) {
	((SuiListBoxImplementation*) impl)->setNextBox(boxID);
}

void SuiListBoxAdapter::setPreviousBox(unsigned int boxID) {
	((SuiListBoxImplementation*) impl)->setPreviousBox(boxID);
}

unsigned long long SuiListBoxAdapter::getNextBox() {
	return ((SuiListBoxImplementation*) impl)->getNextBox();
}

unsigned long long SuiListBoxAdapter::getPreviousBox() {
	return ((SuiListBoxImplementation*) impl)->getPreviousBox();
}

bool SuiListBoxAdapter::isListBox() {
	return ((SuiListBoxImplementation*) impl)->isListBox();
}

/*
 *	SuiListBoxHelper
 */

SuiListBoxHelper* SuiListBoxHelper::staticInitializer = SuiListBoxHelper::instance();

SuiListBoxHelper::SuiListBoxHelper() {
	className = "SuiListBox";

	Core::getObjectBroker()->registerClass(className, this);
}

void SuiListBoxHelper::finalizeHelper() {
	SuiListBoxHelper::finalize();
}

DistributedObject* SuiListBoxHelper::instantiateObject() {
	return new SuiListBox(DummyConstructorParameter::instance());
}

DistributedObjectServant* SuiListBoxHelper::instantiateServant() {
	return new SuiListBoxImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SuiListBoxHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SuiListBoxAdapter((SuiListBoxImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

