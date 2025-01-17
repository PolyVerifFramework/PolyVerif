"""Scenic world model for the LGSVL Simulator."""

from scenic.domains.driving.model import *
from scenic.simulators.lgsvl.behaviors import *

try:
    import lgsvl
    EGO_TYPE = lgsvl.AgentType.EGO
    NPC_TYPE = lgsvl.AgentType.NPC
    PEDESTRIAN_TYPE = lgsvl.AgentType.PEDESTRIAN
    
    from scenic.simulators.lgsvl.simulator import LGSVLSimulator
    from scenic.simulators.lgsvl.actions import *
    import scenic.simulators.lgsvl.utils as utils
except ModuleNotFoundError:
    # to allow generating static scenes without having the lgsvl package installed
    EGO_TYPE = 'EGO'
    NPC_TYPE = 'NPC'
    PEDESTRIAN_TYPE = 'PEDESTRIAN'
    

    import warnings
    warnings.warn('the "lgsvl" package is not installed; '
                  'will not be able to run dynamic simulations')

    def LGSVLSimulator(*args, **kwargs):
        raise RuntimeError('the "lgsvl" package is required to run simulations '
                           'from this scenario')

if 'lgsvl_map' not in globalParameters:
    raise RuntimeError('need to specify map before importing LGSVL model '
                       '(set the global parameter "lgsvl_map")')
simulator LGSVLSimulator(globalParameters.lgsvl_map)

## LGSVL objects

class LGSVLObject(DrivingObject):
    lgsvlObject: None   # corresponding lgsvl.Agent object
    state: None     # LGSVL state, used internally to accumulate state updates

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self._stateUpdated = False

    def setPosition(self, pos, elevation):
        self.state.position = utils.scenicToLGSVLPosition(pos, elevation)
        self._stateUpdated = True

    def setVelocity(self, vel):
        self.state.velocity = utils.scenicToLGSVLPosition(vel)
        self._stateUpdated = True

# TODO: Get vehicle models, dimensions from LGSVL
class Vehicle(Vehicle, LGSVLObject):
    pass

class AutowareEgoCar(Vehicle, Steers):
    lgsvlName: '5ab8175f-e1f1-427c-a86e-e882fa842978'
    lgsvlAgentType: EGO_TYPE
    dreamview: None
       
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self._control = None    # used internally to accumulate control updates

    @property
    def control(self):
        if self._control is None:
            self._control = lgsvl.VehicleControl()
            self._stickyControl = True
        return self._control

    def setThrottle(self, throttle):
        print("in scenic model : ",throttle)
        self.control.throttle = throttle

    def setSteering(self, steering):
        self.control.steering = steering

    def setBraking(self, braking):
        self.control.braking = braking

    def setHandbrake(self, handbrake):
        self.control.handbrake = handbrake

    def setReverse(self, reverse):
        self.control.reverse = reverse

# A plain Car is an EgoCar so that the Steers protocol is supported
(Car) = (AutowareEgoCar)

class AutowareCar(AutowareEgoCar):
    lgsvlName: '5ab8175f-e1f1-427c-a86e-e882fa842978'   #'Lexus2016RXHybrid (Autoware)'
    autowareVehicle:   ' Jaguar2015XE'    #'Lexus2016RXHybrid'
    autowareModules:['Localization', 'Perception', 'Transform', 'Routing',
                    'Prediction', 'Planning', 'Camera']
    bridgeHost: '127.0.0.1'
    bridgePort: 9090

    dreamview: None     # connection to Dreamview (set at runtime)
  
class NPCCar(NPCCar, Vehicle):
    lgsvlName: 'Sedan'
    lgsvlAgentType: NPC_TYPE

class Bus(NPCCar, Vehicle):
    lgsvlName: 'SchoolBus'
    lgsvlAgentType: NPC_TYPE

class Bus(NPCCar, Vehicle):
    lgsvlName: 'Bicyclist'
    lgsvlAgentType: NPC_TYPE


class Pedestrian(Pedestrian, LGSVLObject, Walks):
    lgsvlName: 'Bob'
    lgsvlAgentType: PEDESTRIAN_TYPE

    def setWalkingDirection(self, heading):
        super().setWalkingDirection(heading)    # TODO use better implementation?

    def setWalkingSpeed(self, speed=5.0):
        super().setWalkingSpeed(speed)
    
class Pedestrian_subclass(Pedestrian,LGSVLObject,Walks):
    ped= ['Howard', 'Johny','Pamela','Presley','EntrepreneurFemale','SegwayKickScooterMaxG30LP']
    lgsvlName: ped
    lgsvlAgentType: PEDESTRIAN_TYPE
    

## Utility classes

class Waypoint(OrientedPoint):
    heading: roadDirection at self.position
    speed: 10