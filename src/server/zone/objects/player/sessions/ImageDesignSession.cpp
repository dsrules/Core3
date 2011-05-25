/*
 *	server/zone/objects/player/sessions/ImageDesignSession.cpp generated by engine3 IDL compiler 0.60
 */

#include "ImageDesignSession.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/player/events/ImageDesignTimeoutEvent.h"


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

#include "server/zone/objects/tangible/TangibleObject.h"

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
 *	ImageDesignSessionStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_INITIALIZESESSION__,RPC_DOPAYMENT__,RPC_CANCELSESSION__,RPC_CLEARSESSION__,RPC_CLEARIDTIMEOUTEVENT__,RPC_DEQUEUEIDTIMEOUTEVENT__,RPC_SESSIONTIMEOUT__};

ImageDesignSession::ImageDesignSession(CreatureObject* parent) : Facade(DummyConstructorParameter::instance()) {
	ImageDesignSessionImplementation* _implementation = new ImageDesignSessionImplementation(parent);
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

ImageDesignSession::ImageDesignSession(DummyConstructorParameter* param) : Facade(param) {
}

ImageDesignSession::~ImageDesignSession() {
}


void ImageDesignSession::initializeTransientMembers() {
	ImageDesignSessionImplementation* _implementation = (ImageDesignSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void ImageDesignSession::startImageDesign(PlayerCreature* designer, PlayerCreature* targetPlayer) {
	ImageDesignSessionImplementation* _implementation = (ImageDesignSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->startImageDesign(designer, targetPlayer);
}

void ImageDesignSession::updateImageDesign(unsigned long long designer, unsigned long long targetPlayer, unsigned long long tent, int type, const ImageDesignData& data) {
	ImageDesignSessionImplementation* _implementation = (ImageDesignSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->updateImageDesign(designer, targetPlayer, tent, type, data);
}

void ImageDesignSession::cancelImageDesign(unsigned long long designer, unsigned long long targetPlayer, unsigned long long tent, int type, const ImageDesignData& data) {
	ImageDesignSessionImplementation* _implementation = (ImageDesignSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->cancelImageDesign(designer, targetPlayer, tent, type, data);
}

int ImageDesignSession::initializeSession() {
	ImageDesignSessionImplementation* _implementation = (ImageDesignSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZESESSION__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->initializeSession();
}

int ImageDesignSession::doPayment() {
	ImageDesignSessionImplementation* _implementation = (ImageDesignSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DOPAYMENT__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->doPayment();
}

int ImageDesignSession::cancelSession() {
	ImageDesignSessionImplementation* _implementation = (ImageDesignSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CANCELSESSION__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->cancelSession();
}

int ImageDesignSession::clearSession() {
	ImageDesignSessionImplementation* _implementation = (ImageDesignSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CLEARSESSION__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->clearSession();
}

void ImageDesignSession::clearIdTimeoutEvent() {
	ImageDesignSessionImplementation* _implementation = (ImageDesignSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CLEARIDTIMEOUTEVENT__);

		method.executeWithVoidReturn();
	} else
		_implementation->clearIdTimeoutEvent();
}

void ImageDesignSession::dequeueIdTimeoutEvent() {
	ImageDesignSessionImplementation* _implementation = (ImageDesignSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DEQUEUEIDTIMEOUTEVENT__);

		method.executeWithVoidReturn();
	} else
		_implementation->dequeueIdTimeoutEvent();
}

void ImageDesignSession::sessionTimeout() {
	ImageDesignSessionImplementation* _implementation = (ImageDesignSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SESSIONTIMEOUT__);

		method.executeWithVoidReturn();
	} else
		_implementation->sessionTimeout();
}

DistributedObjectServant* ImageDesignSession::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void ImageDesignSession::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<ImageDesignSessionImplementation*>(servant));
}

/*
 *	ImageDesignSessionImplementation
 */

ImageDesignSessionImplementation::ImageDesignSessionImplementation(DummyConstructorParameter* param) : FacadeImplementation(param) {
	_initializeImplementation();
}


ImageDesignSessionImplementation::~ImageDesignSessionImplementation() {
}


void ImageDesignSessionImplementation::finalize() {
}

void ImageDesignSessionImplementation::_initializeImplementation() {
	_setClassHelper(ImageDesignSessionHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void ImageDesignSessionImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ImageDesignSession*) stub;
	FacadeImplementation::_setStub(stub);
}

DistributedObjectStub* ImageDesignSessionImplementation::_getStub() {
	return _this;
}

ImageDesignSessionImplementation::operator const ImageDesignSession*() {
	return _this;
}

Object* ImageDesignSessionImplementation::clone() {
	return dynamic_cast<Object*>(new ImageDesignSessionImplementation(*this));
}


void ImageDesignSessionImplementation::lock(bool doLock) {
}

void ImageDesignSessionImplementation::lock(ManagedObject* obj) {
}

void ImageDesignSessionImplementation::rlock(bool doLock) {
}

void ImageDesignSessionImplementation::wlock(bool doLock) {
}

void ImageDesignSessionImplementation::wlock(ManagedObject* obj) {
}

void ImageDesignSessionImplementation::unlock(bool doLock) {
}

void ImageDesignSessionImplementation::runlock(bool doLock) {
}

void ImageDesignSessionImplementation::_serializationHelperMethod() {
	FacadeImplementation::_serializationHelperMethod();

	_setClassName("ImageDesignSession");

}

void ImageDesignSessionImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(ImageDesignSessionImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ImageDesignSessionImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (FacadeImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "imageDesignManager") {
		TypeInfo<Reference<ImageDesignManager* > >::parseFromBinaryStream(&imageDesignManager, stream);
		return true;
	}

	if (_name == "designerCreature") {
		TypeInfo<ManagedWeakReference<PlayerCreature* > >::parseFromBinaryStream(&designerCreature, stream);
		return true;
	}

	if (_name == "targetCreature") {
		TypeInfo<ManagedWeakReference<PlayerCreature* > >::parseFromBinaryStream(&targetCreature, stream);
		return true;
	}

	if (_name == "imageDesignData") {
		TypeInfo<ImageDesignData >::parseFromBinaryStream(&imageDesignData, stream);
		return true;
	}


	return false;
}

void ImageDesignSessionImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ImageDesignSessionImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ImageDesignSessionImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "imageDesignManager";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<Reference<ImageDesignManager* > >::toBinaryStream(&imageDesignManager, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "designerCreature";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedWeakReference<PlayerCreature* > >::toBinaryStream(&designerCreature, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "targetCreature";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedWeakReference<PlayerCreature* > >::toBinaryStream(&targetCreature, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "imageDesignData";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ImageDesignData >::toBinaryStream(&imageDesignData, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 4 + FacadeImplementation::writeObjectMembers(stream);
}

ImageDesignSessionImplementation::ImageDesignSessionImplementation(CreatureObject* parent) {
	_initializeImplementation();
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		Logger.setLoggingName("ImageDesignSession");
	Logger::setLoggingName("ImageDesignSession");
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		Logger.setLogging(true);
	Logger::setLogging(true);
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		initializeSession();
	initializeSession();
}

int ImageDesignSessionImplementation::initializeSession() {
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		designerCreature = null;
	designerCreature = NULL;
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		targetCreature = null;
	targetCreature = NULL;
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		imageDesignManager = null;
	imageDesignManager = NULL;
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		idTimeoutEvent = null;
	idTimeoutEvent = NULL;
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		return 0;
	return 0;
}

int ImageDesignSessionImplementation::cancelSession() {
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		if 
	if (designerCreature != NULL)	// server/zone/objects/player/sessions/ImageDesignSession.idl():  			designerCreature.dropActiveSession(SessionFacadeType.IMAGEDESIGN);
	designerCreature->dropActiveSession(SessionFacadeType::IMAGEDESIGN);
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		dequeueIdTimeoutEvent(
	if (targetCreature != NULL)	// server/zone/objects/player/sessions/ImageDesignSession.idl():  			targetCreature.dropActiveSession(SessionFacadeType.IMAGEDESIGN);
	targetCreature->dropActiveSession(SessionFacadeType::IMAGEDESIGN);
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		dequeueIdTimeoutEvent();
	dequeueIdTimeoutEvent();
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		return 0;
	return 0;
}

int ImageDesignSessionImplementation::clearSession() {
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		return 0;
	return 0;
}

void ImageDesignSessionImplementation::clearIdTimeoutEvent() {
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		idTimeoutEvent = null;
	idTimeoutEvent = NULL;
}

void ImageDesignSessionImplementation::dequeueIdTimeoutEvent() {
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  	}
	if (idTimeoutEvent != NULL){
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  			idTimeoutEvent.cancel();
	idTimeoutEvent->cancel();
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  			idTimeoutEvent = null;
	idTimeoutEvent = NULL;
}
}

void ImageDesignSessionImplementation::sessionTimeout() {
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		if 
	if (designerCreature != NULL){
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  			designerCreature.sendSystemMessage("Image Design session has timed out. Changes aborted.");
	designerCreature->sendSystemMessage("Image Design session has timed out. Changes aborted.");
}
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  	}
	if (targetCreature != NULL){
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  			targetCreature.sendSystemMessage("Image Design session has timed out. Changes aborted.");
	targetCreature->sendSystemMessage("Image Design session has timed out. Changes aborted.");
}
}

/*
 *	ImageDesignSessionAdapter
 */

ImageDesignSessionAdapter::ImageDesignSessionAdapter(ImageDesignSessionImplementation* obj) : FacadeAdapter(obj) {
}

Packet* ImageDesignSessionAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_INITIALIZESESSION__:
		resp->insertSignedInt(initializeSession());
		break;
	case RPC_DOPAYMENT__:
		resp->insertSignedInt(doPayment());
		break;
	case RPC_CANCELSESSION__:
		resp->insertSignedInt(cancelSession());
		break;
	case RPC_CLEARSESSION__:
		resp->insertSignedInt(clearSession());
		break;
	case RPC_CLEARIDTIMEOUTEVENT__:
		clearIdTimeoutEvent();
		break;
	case RPC_DEQUEUEIDTIMEOUTEVENT__:
		dequeueIdTimeoutEvent();
		break;
	case RPC_SESSIONTIMEOUT__:
		sessionTimeout();
		break;
	default:
		return NULL;
	}

	return resp;
}

void ImageDesignSessionAdapter::initializeTransientMembers() {
	((ImageDesignSessionImplementation*) impl)->initializeTransientMembers();
}

int ImageDesignSessionAdapter::initializeSession() {
	return ((ImageDesignSessionImplementation*) impl)->initializeSession();
}

int ImageDesignSessionAdapter::doPayment() {
	return ((ImageDesignSessionImplementation*) impl)->doPayment();
}

int ImageDesignSessionAdapter::cancelSession() {
	return ((ImageDesignSessionImplementation*) impl)->cancelSession();
}

int ImageDesignSessionAdapter::clearSession() {
	return ((ImageDesignSessionImplementation*) impl)->clearSession();
}

void ImageDesignSessionAdapter::clearIdTimeoutEvent() {
	((ImageDesignSessionImplementation*) impl)->clearIdTimeoutEvent();
}

void ImageDesignSessionAdapter::dequeueIdTimeoutEvent() {
	((ImageDesignSessionImplementation*) impl)->dequeueIdTimeoutEvent();
}

void ImageDesignSessionAdapter::sessionTimeout() {
	((ImageDesignSessionImplementation*) impl)->sessionTimeout();
}

/*
 *	ImageDesignSessionHelper
 */

ImageDesignSessionHelper* ImageDesignSessionHelper::staticInitializer = ImageDesignSessionHelper::instance();

ImageDesignSessionHelper::ImageDesignSessionHelper() {
	className = "ImageDesignSession";

	Core::getObjectBroker()->registerClass(className, this);
}

void ImageDesignSessionHelper::finalizeHelper() {
	ImageDesignSessionHelper::finalize();
}

DistributedObject* ImageDesignSessionHelper::instantiateObject() {
	return new ImageDesignSession(DummyConstructorParameter::instance());
}

DistributedObjectServant* ImageDesignSessionHelper::instantiateServant() {
	return new ImageDesignSessionImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ImageDesignSessionHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ImageDesignSessionAdapter((ImageDesignSessionImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

