/*
 *	server/zone/objects/tangible/weapon/WeaponObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "WeaponObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

/*
 *	WeaponObjectStub
 */

WeaponObject::WeaponObject() : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new WeaponObjectImplementation();
	_impl->_setStub(this);
}

WeaponObject::WeaponObject(DummyConstructorParameter* param) : TangibleObject(param) {
}

WeaponObject::~WeaponObject() {
}


TransactionalObject* WeaponObject::clone() {
	WeaponObject* objectCopy = new WeaponObject(DummyConstructorParameter::instance());
	objectCopy->_impl = new WeaponObjectImplementation(DummyConstructorParameter::instance());
	*(objectCopy->_impl) = *_impl;
	return (TransactionalObject*) objectCopy;
}


void WeaponObject::loadTemplateData(LuaObject* templateData) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((WeaponObjectImplementation*) _impl)->loadTemplateData(templateData);
}

void WeaponObject::initializeTransientMembers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((WeaponObjectImplementation*) _impl)->initializeTransientMembers();
}

void WeaponObject::sendBaselinesTo(SceneObject* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((WeaponObjectImplementation*) _impl)->sendBaselinesTo(player);
}

void WeaponObject::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((WeaponObjectImplementation*) _impl)->fillAttributeList(msg, object);
}

bool WeaponObject::isCertifiedFor(PlayerCreature* object) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(object);

		return method.executeWithBooleanReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->isCertifiedFor(object);
}

Vector<String>* WeaponObject::getDamageModifiers() {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((WeaponObjectImplementation*) _impl)->getDamageModifiers();
}

Vector<String>* WeaponObject::getSpeedModifiers() {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((WeaponObjectImplementation*) _impl)->getSpeedModifiers();
}

Vector<String>* WeaponObject::getCreatureAccuracyModifiers() {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((WeaponObjectImplementation*) _impl)->getCreatureAccuracyModifiers();
}

Vector<String>* WeaponObject::getDefenderDefenseModifiers() {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((WeaponObjectImplementation*) _impl)->getDefenderDefenseModifiers();
}

void WeaponObject::setCertified(bool cert) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addBooleanParameter(cert);

		method.executeWithVoidReturn();
	} else
		((WeaponObjectImplementation*) _impl)->setCertified(cert);
}

int WeaponObject::getAttackType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithSignedIntReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getAttackType();
}

bool WeaponObject::isCertified() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithBooleanReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->isCertified();
}

int WeaponObject::getPointBlankAccuracy() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithSignedIntReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getPointBlankAccuracy();
}

int WeaponObject::getPointBlankRange() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithSignedIntReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getPointBlankRange();
}

int WeaponObject::getIdealRange() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		return method.executeWithSignedIntReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getIdealRange();
}

int WeaponObject::getMaxRange() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithSignedIntReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getMaxRange();
}

int WeaponObject::getIdealAccuracy() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithSignedIntReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getIdealAccuracy();
}

int WeaponObject::getArmorPiercing() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithSignedIntReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getArmorPiercing();
}

int WeaponObject::getMaxRangeAccuracy() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		return method.executeWithSignedIntReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getMaxRangeAccuracy();
}

float WeaponObject::getAttackSpeed() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		return method.executeWithFloatReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getAttackSpeed();
}

float WeaponObject::getMaxDamage() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);

		return method.executeWithFloatReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getMaxDamage();
}

float WeaponObject::getMinDamage() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);

		return method.executeWithFloatReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getMinDamage();
}

float WeaponObject::getWoundsRatio() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);

		return method.executeWithFloatReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getWoundsRatio();
}

int WeaponObject::getHealthAttackCost() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);

		return method.executeWithSignedIntReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getHealthAttackCost();
}

int WeaponObject::getActionAttackCost() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);

		return method.executeWithSignedIntReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getActionAttackCost();
}

int WeaponObject::getMindAttackCost() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);

		return method.executeWithSignedIntReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getMindAttackCost();
}

int WeaponObject::getForceCost() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);

		return method.executeWithSignedIntReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getForceCost();
}

int WeaponObject::getDamageType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);

		return method.executeWithSignedIntReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->getDamageType();
}

bool WeaponObject::hasMeleeAttack() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);

		return method.executeWithBooleanReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->hasMeleeAttack();
}

bool WeaponObject::hasRangedAttack() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 29);

		return method.executeWithBooleanReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->hasRangedAttack();
}

bool WeaponObject::isUnarmedWeapon() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 30);

		return method.executeWithBooleanReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->isUnarmedWeapon();
}

bool WeaponObject::isMeleeWeapon() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 31);

		return method.executeWithBooleanReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->isMeleeWeapon();
}

bool WeaponObject::isRangedWeapon() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 32);

		return method.executeWithBooleanReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->isRangedWeapon();
}

bool WeaponObject::isRifleWeapon() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 33);

		return method.executeWithBooleanReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->isRifleWeapon();
}

bool WeaponObject::isPistolWeapon() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 34);

		return method.executeWithBooleanReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->isPistolWeapon();
}

bool WeaponObject::isOneHandMeleeWeapon() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 35);

		return method.executeWithBooleanReturn();
	} else
		return ((WeaponObjectImplementation*) _impl)->isOneHandMeleeWeapon();
}

/*
 *	WeaponObjectImplementation
 */

WeaponObjectImplementation::WeaponObjectImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}

WeaponObjectImplementation::~WeaponObjectImplementation() {
}


void WeaponObjectImplementation::finalize() {
}

void WeaponObjectImplementation::_initializeImplementation() {
	_setClassHelper(WeaponObjectHelper::instance());

	_serializationHelperMethod();
}

void WeaponObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (WeaponObject*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* WeaponObjectImplementation::_getStub() {
	return _this;
}

WeaponObjectImplementation::operator const WeaponObject*() {
	return _this;
}

void WeaponObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void WeaponObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void WeaponObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void WeaponObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void WeaponObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void WeaponObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void WeaponObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void WeaponObjectImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("WeaponObject");

	addSerializableVariable("attackType", &attackType);
	addSerializableVariable("weaponEffect", &weaponEffect);
	addSerializableVariable("weaponEffectIndex", &weaponEffectIndex);
	addSerializableVariable("certified", &certified);
	addSerializableVariable("armorPiercing", &armorPiercing);
	addSerializableVariable("pointBlankAccuracy", &pointBlankAccuracy);
	addSerializableVariable("pointBlankRange", &pointBlankRange);
	addSerializableVariable("idealRange", &idealRange);
	addSerializableVariable("idealAccuracy", &idealAccuracy);
	addSerializableVariable("maxRange", &maxRange);
	addSerializableVariable("maxRangeAccuracy", &maxRangeAccuracy);
	addSerializableVariable("damageType", &damageType);
	addSerializableVariable("attackSpeed", &attackSpeed);
	addSerializableVariable("minDamage", &minDamage);
	addSerializableVariable("maxDamage", &maxDamage);
	addSerializableVariable("area", &area);
	addSerializableVariable("woundsRatio", &woundsRatio);
	addSerializableVariable("healthAttackCost", &healthAttackCost);
	addSerializableVariable("actionAttackCost", &actionAttackCost);
	addSerializableVariable("mindAttackCost", &mindAttackCost);
	addSerializableVariable("forceCost", &forceCost);
	addSerializableVariable("damageModifiers", &damageModifiers);
	addSerializableVariable("speedModifiers", &speedModifiers);
	addSerializableVariable("creatureAccuracyModifiers", &creatureAccuracyModifiers);
	addSerializableVariable("defenderDefenseModifiers", &defenderDefenseModifiers);
	addSerializableVariable("certificationsRequired", &certificationsRequired);
}

WeaponObjectImplementation::WeaponObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/weapon/WeaponObject.idl(131):  		certified = false;
	certified = false;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(132):  		armorPiercing = 0;
	armorPiercing = 0;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(134):  		healthAttackCost = 0;
	healthAttackCost = 0;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(135):  		actionAttackCost = 0;
	actionAttackCost = 0;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(136):  		mindAttackCost = 0;
	mindAttackCost = 0;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(137):  		forceCost = 0;
	forceCost = 0;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(139):  		pointBlankAccuracy = 0;
	pointBlankAccuracy = 0;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(140):  		pointBlankRange = 0;
	pointBlankRange = 0;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(142):  		idealRange = 0;
	idealRange = 0;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(143):  		idealAccuracy = 0;
	idealAccuracy = 0;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(145):  		maxRange = 0;
	maxRange = 0;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(146):  		maxRangeAccuracy = 0;
	maxRangeAccuracy = 0;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(148):  		damageType = 0;
	damageType = 0;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(150):  		minDamage = 0;
	minDamage = 0;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(151):  		maxDamage = 10;
	maxDamage = 10;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(153):  		woundsRatio = 0;
	woundsRatio = 0;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(155):  		area = 0;
	area = 0;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(157):  		attackSpeed = 1;
	attackSpeed = 1;
	// server/zone/objects/tangible/weapon/WeaponObject.idl(159):  		Logger.setLoggingName("WeaponObject");
	Logger::setLoggingName("WeaponObject");
}

Vector<String>* WeaponObjectImplementation::getDamageModifiers() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(189):  		return damageModifiers;
	return (&damageModifiers);
}

Vector<String>* WeaponObjectImplementation::getSpeedModifiers() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(194):  		return speedModifiers;
	return (&speedModifiers);
}

Vector<String>* WeaponObjectImplementation::getCreatureAccuracyModifiers() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(199):  		return creatureAccuracyModifiers;
	return (&creatureAccuracyModifiers);
}

Vector<String>* WeaponObjectImplementation::getDefenderDefenseModifiers() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(204):  		return defenderDefenseModifiers;
	return (&defenderDefenseModifiers);
}

void WeaponObjectImplementation::setCertified(bool cert) {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(208):  		certified = cert;
	certified = cert;
}

int WeaponObjectImplementation::getAttackType() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(212):  		return attackType;
	return attackType;
}

bool WeaponObjectImplementation::isCertified() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(216):  		return certified;
	return certified;
}

int WeaponObjectImplementation::getPointBlankAccuracy() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(220):  		return pointBlankAccuracy;
	return pointBlankAccuracy;
}

int WeaponObjectImplementation::getPointBlankRange() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(224):  		return pointBlankRange;
	return pointBlankRange;
}

int WeaponObjectImplementation::getIdealRange() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(228):  		return idealRange;
	return idealRange;
}

int WeaponObjectImplementation::getMaxRange() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(232):  		return maxRange;
	return maxRange;
}

int WeaponObjectImplementation::getIdealAccuracy() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(236):  		return idealAccuracy;
	return idealAccuracy;
}

int WeaponObjectImplementation::getArmorPiercing() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(240):  		return armorPiercing;
	return armorPiercing;
}

int WeaponObjectImplementation::getMaxRangeAccuracy() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(244):  		return maxRangeAccuracy;
	return maxRangeAccuracy;
}

float WeaponObjectImplementation::getAttackSpeed() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(248):  		return attackSpeed;
	return attackSpeed;
}

float WeaponObjectImplementation::getMaxDamage() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(252):  		return maxDamage;
	return maxDamage;
}

float WeaponObjectImplementation::getMinDamage() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(256):  		return minDamage;
	return minDamage;
}

float WeaponObjectImplementation::getWoundsRatio() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(260):  		return woundsRatio;
	return woundsRatio;
}

int WeaponObjectImplementation::getHealthAttackCost() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(264):  		return healthAttackCost;
	return healthAttackCost;
}

int WeaponObjectImplementation::getActionAttackCost() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(268):  		return actionAttackCost;
	return actionAttackCost;
}

int WeaponObjectImplementation::getMindAttackCost() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(272):  		return mindAttackCost;
	return mindAttackCost;
}

int WeaponObjectImplementation::getForceCost() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(276):  		return forceCost;
	return forceCost;
}

int WeaponObjectImplementation::getDamageType() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(280):  		return damageType;
	return damageType;
}

bool WeaponObjectImplementation::hasMeleeAttack() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(284):  		return attackType == MELEEATTACK;
	return attackType == MELEEATTACK;
}

bool WeaponObjectImplementation::hasRangedAttack() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(288):  		return attackType == RANGEDATTACK;
	return attackType == RANGEDATTACK;
}

bool WeaponObjectImplementation::isUnarmedWeapon() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(292):  		return super.gameObjectType == SceneObject.WEAPON;
	return TangibleObjectImplementation::gameObjectType == SceneObject::WEAPON;
}

bool WeaponObjectImplementation::isMeleeWeapon() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(296):  		return false;
	return false;
}

bool WeaponObjectImplementation::isRangedWeapon() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(300):  		return false;
	return false;
}

bool WeaponObjectImplementation::isRifleWeapon() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(304):  		return false;
	return false;
}

bool WeaponObjectImplementation::isPistolWeapon() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(308):  		return false;
	return false;
}

bool WeaponObjectImplementation::isOneHandMeleeWeapon() {
	// server/zone/objects/tangible/weapon/WeaponObject.idl(312):  		return false;
	return false;
}

/*
 *	WeaponObjectAdapter
 */

WeaponObjectAdapter::WeaponObjectAdapter(WeaponObjectImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* WeaponObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		sendBaselinesTo((SceneObject*) inv->getObjectParameter());
		break;
	case 8:
		resp->insertBoolean(isCertifiedFor((PlayerCreature*) inv->getObjectParameter()));
		break;
	case 9:
		setCertified(inv->getBooleanParameter());
		break;
	case 10:
		resp->insertSignedInt(getAttackType());
		break;
	case 11:
		resp->insertBoolean(isCertified());
		break;
	case 12:
		resp->insertSignedInt(getPointBlankAccuracy());
		break;
	case 13:
		resp->insertSignedInt(getPointBlankRange());
		break;
	case 14:
		resp->insertSignedInt(getIdealRange());
		break;
	case 15:
		resp->insertSignedInt(getMaxRange());
		break;
	case 16:
		resp->insertSignedInt(getIdealAccuracy());
		break;
	case 17:
		resp->insertSignedInt(getArmorPiercing());
		break;
	case 18:
		resp->insertSignedInt(getMaxRangeAccuracy());
		break;
	case 19:
		resp->insertFloat(getAttackSpeed());
		break;
	case 20:
		resp->insertFloat(getMaxDamage());
		break;
	case 21:
		resp->insertFloat(getMinDamage());
		break;
	case 22:
		resp->insertFloat(getWoundsRatio());
		break;
	case 23:
		resp->insertSignedInt(getHealthAttackCost());
		break;
	case 24:
		resp->insertSignedInt(getActionAttackCost());
		break;
	case 25:
		resp->insertSignedInt(getMindAttackCost());
		break;
	case 26:
		resp->insertSignedInt(getForceCost());
		break;
	case 27:
		resp->insertSignedInt(getDamageType());
		break;
	case 28:
		resp->insertBoolean(hasMeleeAttack());
		break;
	case 29:
		resp->insertBoolean(hasRangedAttack());
		break;
	case 30:
		resp->insertBoolean(isUnarmedWeapon());
		break;
	case 31:
		resp->insertBoolean(isMeleeWeapon());
		break;
	case 32:
		resp->insertBoolean(isRangedWeapon());
		break;
	case 33:
		resp->insertBoolean(isRifleWeapon());
		break;
	case 34:
		resp->insertBoolean(isPistolWeapon());
		break;
	case 35:
		resp->insertBoolean(isOneHandMeleeWeapon());
		break;
	default:
		return NULL;
	}

	return resp;
}

void WeaponObjectAdapter::initializeTransientMembers() {
	((WeaponObjectImplementation*) impl)->initializeTransientMembers();
}

void WeaponObjectAdapter::sendBaselinesTo(SceneObject* player) {
	((WeaponObjectImplementation*) impl)->sendBaselinesTo(player);
}

bool WeaponObjectAdapter::isCertifiedFor(PlayerCreature* object) {
	return ((WeaponObjectImplementation*) impl)->isCertifiedFor(object);
}

void WeaponObjectAdapter::setCertified(bool cert) {
	((WeaponObjectImplementation*) impl)->setCertified(cert);
}

int WeaponObjectAdapter::getAttackType() {
	return ((WeaponObjectImplementation*) impl)->getAttackType();
}

bool WeaponObjectAdapter::isCertified() {
	return ((WeaponObjectImplementation*) impl)->isCertified();
}

int WeaponObjectAdapter::getPointBlankAccuracy() {
	return ((WeaponObjectImplementation*) impl)->getPointBlankAccuracy();
}

int WeaponObjectAdapter::getPointBlankRange() {
	return ((WeaponObjectImplementation*) impl)->getPointBlankRange();
}

int WeaponObjectAdapter::getIdealRange() {
	return ((WeaponObjectImplementation*) impl)->getIdealRange();
}

int WeaponObjectAdapter::getMaxRange() {
	return ((WeaponObjectImplementation*) impl)->getMaxRange();
}

int WeaponObjectAdapter::getIdealAccuracy() {
	return ((WeaponObjectImplementation*) impl)->getIdealAccuracy();
}

int WeaponObjectAdapter::getArmorPiercing() {
	return ((WeaponObjectImplementation*) impl)->getArmorPiercing();
}

int WeaponObjectAdapter::getMaxRangeAccuracy() {
	return ((WeaponObjectImplementation*) impl)->getMaxRangeAccuracy();
}

float WeaponObjectAdapter::getAttackSpeed() {
	return ((WeaponObjectImplementation*) impl)->getAttackSpeed();
}

float WeaponObjectAdapter::getMaxDamage() {
	return ((WeaponObjectImplementation*) impl)->getMaxDamage();
}

float WeaponObjectAdapter::getMinDamage() {
	return ((WeaponObjectImplementation*) impl)->getMinDamage();
}

float WeaponObjectAdapter::getWoundsRatio() {
	return ((WeaponObjectImplementation*) impl)->getWoundsRatio();
}

int WeaponObjectAdapter::getHealthAttackCost() {
	return ((WeaponObjectImplementation*) impl)->getHealthAttackCost();
}

int WeaponObjectAdapter::getActionAttackCost() {
	return ((WeaponObjectImplementation*) impl)->getActionAttackCost();
}

int WeaponObjectAdapter::getMindAttackCost() {
	return ((WeaponObjectImplementation*) impl)->getMindAttackCost();
}

int WeaponObjectAdapter::getForceCost() {
	return ((WeaponObjectImplementation*) impl)->getForceCost();
}

int WeaponObjectAdapter::getDamageType() {
	return ((WeaponObjectImplementation*) impl)->getDamageType();
}

bool WeaponObjectAdapter::hasMeleeAttack() {
	return ((WeaponObjectImplementation*) impl)->hasMeleeAttack();
}

bool WeaponObjectAdapter::hasRangedAttack() {
	return ((WeaponObjectImplementation*) impl)->hasRangedAttack();
}

bool WeaponObjectAdapter::isUnarmedWeapon() {
	return ((WeaponObjectImplementation*) impl)->isUnarmedWeapon();
}

bool WeaponObjectAdapter::isMeleeWeapon() {
	return ((WeaponObjectImplementation*) impl)->isMeleeWeapon();
}

bool WeaponObjectAdapter::isRangedWeapon() {
	return ((WeaponObjectImplementation*) impl)->isRangedWeapon();
}

bool WeaponObjectAdapter::isRifleWeapon() {
	return ((WeaponObjectImplementation*) impl)->isRifleWeapon();
}

bool WeaponObjectAdapter::isPistolWeapon() {
	return ((WeaponObjectImplementation*) impl)->isPistolWeapon();
}

bool WeaponObjectAdapter::isOneHandMeleeWeapon() {
	return ((WeaponObjectImplementation*) impl)->isOneHandMeleeWeapon();
}

/*
 *	WeaponObjectHelper
 */

WeaponObjectHelper* WeaponObjectHelper::staticInitializer = WeaponObjectHelper::instance();

WeaponObjectHelper::WeaponObjectHelper() {
	className = "WeaponObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void WeaponObjectHelper::finalizeHelper() {
	WeaponObjectHelper::finalize();
}

DistributedObject* WeaponObjectHelper::instantiateObject() {
	return new WeaponObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* WeaponObjectHelper::instantiateServant() {
	return new WeaponObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* WeaponObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new WeaponObjectAdapter((WeaponObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

