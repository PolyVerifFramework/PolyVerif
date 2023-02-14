"""Behaviors for dynamic agents in LGSVL."""

from scenic.domains.driving.behaviors import *	# use all common driving behaviors
import scenic.domains.driving.model as _model

try:
    from scenic.simulators.lgsvl.actions import *
except ModuleNotFoundError:
    pass    # ignore; error will be caught later if user attempts to run a simulation

behavior DriveTo(target):
	action = SetDestinationAction(target)
	while True:
		take action

behavior WalkBehavior(maxSpeed=1.4):
	take SetWalkAction()

behavior FollowWaypoints(waypoints):
	action = FollowWaypointsAction(waypoints)
	while True:
		take action

behavior Egobehavior(waypoints):
	action = TrackWaypointsAction(waypoints)
	while True:
		take action

