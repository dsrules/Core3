/*
 *	server/zone/objects/draftschematic/DraftSchematicIngredient.cpp generated by engine3 IDL compiler 0.55
 */

#include "DraftSchematicIngredient.h"

#include "DraftSchematicIngredientImplementation.h"

#include "../../packets/object/ObjectControllerMessage.h"

/*
 *	DraftSchematicIngredientStub
 */

DraftSchematicIngredient::DraftSchematicIngredient(const string& ingredientTemplateName, const string& ingredientTitleName, bool optional, const string& resourceType, unsigned int resourceQuantity, unsigned int combineType) {
	_impl = new DraftSchematicIngredientImplementation(ingredientTemplateName, ingredientTitleName, optional, resourceType, resourceQuantity, combineType);
	_impl->_setStub(this);
}

DraftSchematicIngredient::DraftSchematicIngredient(DraftSchematicIngredient* ingredient) {
	_impl = new DraftSchematicIngredientImplementation(ingredient);
	_impl->_setStub(this);
}

DraftSchematicIngredient::DraftSchematicIngredient(DummyConstructorParameter* param) {
	_impl = NULL;
}

DraftSchematicIngredient::~DraftSchematicIngredient() {
}

void DraftSchematicIngredient::helperSendToPlayer(ObjectControllerMessage* msg) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(msg);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicIngredientImplementation*) _impl)->helperSendToPlayer(msg);
}

string& DraftSchematicIngredient::getTemplateName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithAsciiReturn(_return_getTemplateName);
		return _return_getTemplateName;
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->getTemplateName();
}

string& DraftSchematicIngredient::getTitleName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithAsciiReturn(_return_getTitleName);
		return _return_getTitleName;
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->getTitleName();
}

string& DraftSchematicIngredient::getResourceType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		method.executeWithAsciiReturn(_return_getResourceType);
		return _return_getResourceType;
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->getResourceType();
}

unsigned int DraftSchematicIngredient::getResourceQuantity() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->getResourceQuantity();
}

unsigned int DraftSchematicIngredient::getCombineType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->getCombineType();
}

bool DraftSchematicIngredient::getOptional() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithBooleanReturn();
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->getOptional();
}

/*
 *	DraftSchematicIngredientAdapter
 */

DraftSchematicIngredientAdapter::DraftSchematicIngredientAdapter(DraftSchematicIngredientImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* DraftSchematicIngredientAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		helperSendToPlayer((ObjectControllerMessage*) inv->getObjectParameter());
		break;
	case 7:
		resp->insertAscii(getTemplateName());
		break;
	case 8:
		resp->insertAscii(getTitleName());
		break;
	case 9:
		resp->insertAscii(getResourceType());
		break;
	case 10:
		resp->insertInt(getResourceQuantity());
		break;
	case 11:
		resp->insertInt(getCombineType());
		break;
	case 12:
		resp->insertBoolean(getOptional());
		break;
	default:
		return NULL;
	}

	return resp;
}

void DraftSchematicIngredientAdapter::helperSendToPlayer(ObjectControllerMessage* msg) {
	return ((DraftSchematicIngredientImplementation*) impl)->helperSendToPlayer(msg);
}

string& DraftSchematicIngredientAdapter::getTemplateName() {
	return ((DraftSchematicIngredientImplementation*) impl)->getTemplateName();
}

string& DraftSchematicIngredientAdapter::getTitleName() {
	return ((DraftSchematicIngredientImplementation*) impl)->getTitleName();
}

string& DraftSchematicIngredientAdapter::getResourceType() {
	return ((DraftSchematicIngredientImplementation*) impl)->getResourceType();
}

unsigned int DraftSchematicIngredientAdapter::getResourceQuantity() {
	return ((DraftSchematicIngredientImplementation*) impl)->getResourceQuantity();
}

unsigned int DraftSchematicIngredientAdapter::getCombineType() {
	return ((DraftSchematicIngredientImplementation*) impl)->getCombineType();
}

bool DraftSchematicIngredientAdapter::getOptional() {
	return ((DraftSchematicIngredientImplementation*) impl)->getOptional();
}

/*
 *	DraftSchematicIngredientHelper
 */

DraftSchematicIngredientHelper* DraftSchematicIngredientHelper::staticInitializer = DraftSchematicIngredientHelper::instance();

DraftSchematicIngredientHelper::DraftSchematicIngredientHelper() {
	className = "DraftSchematicIngredient";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void DraftSchematicIngredientHelper::finalizeHelper() {
	DraftSchematicIngredientHelper::finalize();
}

DistributedObject* DraftSchematicIngredientHelper::instantiateObject() {
	return new DraftSchematicIngredient(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DraftSchematicIngredientHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DraftSchematicIngredientAdapter((DraftSchematicIngredientImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	DraftSchematicIngredientServant
 */

DraftSchematicIngredientServant::DraftSchematicIngredientServant() {
	_classHelper = DraftSchematicIngredientHelper::instance();
}

DraftSchematicIngredientServant::~DraftSchematicIngredientServant() {
}

void DraftSchematicIngredientServant::_setStub(DistributedObjectStub* stub) {
	_this = (DraftSchematicIngredient*) stub;
}

DistributedObjectStub* DraftSchematicIngredientServant::_getStub() {
	return _this;
}

