#!/bin/bash


scenic examples/driving/driving/oas_scenario_28.scenic \
    --simulate \
    --model scenic.simulators.lgsvl.model \
    --time 200 \
    --count 2 \
    --param map tests/formats/opendrive/maps/LGSVL/cubetown.xodr \
    --param lgsvl_map CubeTown