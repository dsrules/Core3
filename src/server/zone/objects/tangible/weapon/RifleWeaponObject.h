/*
 *	server/zone/objects/tangible/weapon/RifleWeaponObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef RIFLEWEAPONOBJECT_H_
#define RIFLEWEAPONOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

#include "server/zone/objects/tangible/weapon/RangedWeaponObject.h"

#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace weapon {

class RifleWeaponObject : public RangedWeaponObject {
public:
	RifleWeaponObject();

	void initializeTransientMembers();

	void initializePrivateData();

	bool isRifleWeapon();

protected:
	RifleWeaponObject(DummyConstructorParameter* param);

	virtual ~RifleWeaponObject();

	friend class RifleWeaponObjectHelper;
};

} // namespace weapon
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::weapon;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace weapon {

class RifleWeaponObjectImplementation : public RangedWeaponObjectImplementation {

public:
	RifleWeaponObjectImplementation();

	RifleWeaponObjectImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	void initializePrivateData();

	bool isRifleWeapon();

	RifleWeaponObject* _this;

	operator const RifleWeaponObject*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~RifleWeaponObjectImplementation();

	TransactionalObject* clone();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class RifleWeaponObject;
	friend class TransactionalObjectHandle<RifleWeaponObjectImplementation*>;
};

class RifleWeaponObjectAdapter : public RangedWeaponObjectAdapter {
public:
	RifleWeaponObjectAdapter(RifleWeaponObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void initializePrivateData();

	bool isRifleWeapon();

};

class RifleWeaponObjectHelper : public DistributedObjectClassHelper, public Singleton<RifleWeaponObjectHelper> {
	static RifleWeaponObjectHelper* staticInitializer;

public:
	RifleWeaponObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<RifleWeaponObjectHelper>;
};

} // namespace weapon
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::weapon;

#endif /*RIFLEWEAPONOBJECT_H_*/
