## *********************************************************
##
## File autogenerated for the yahboomcar_bringup package
## by the dynamic_reconfigure package.
## Please do not edit.
##
## ********************************************************/

from dynamic_reconfigure.encoding import extract_params

inf = float('inf')

config_description = {'name': 'Default', 'type': '', 'state': True, 'cstate': 'true', 'id': 0, 'parent': 0, 'parameters': [{'name': 'direction', 'type': 'int', 'default': 1, 'level': 0, 'description': 'A size parameter which is edited via an enum', 'min': 0, 'max': 1, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': "{'enum': [{'name': 'Y', 'type': 'int', 'value': 0, 'srcline': 9, 'srcfile': '/root/yahboomcar_ws/src/yahboomcar_bringup/cfg/CalibrateLinear.cfg', 'description': 'first data', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'X', 'type': 'int', 'value': 1, 'srcline': 9, 'srcfile': '/root/yahboomcar_ws/src/yahboomcar_bringup/cfg/CalibrateLinear.cfg', 'description': 'two data', 'ctype': 'int', 'cconsttype': 'const int'}], 'enum_description': 'An enum to set size'}", 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'test_distance', 'type': 'double', 'default': 1.0, 'level': 0, 'description': 'Test distance in meters', 'min': 0.0, 'max': 2.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'speed', 'type': 'double', 'default': 0.3, 'level': 0, 'description': 'Robot speed in meters per second', 'min': 0.0, 'max': 1.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'tolerance', 'type': 'double', 'default': 0.03, 'level': 0, 'description': 'Error tolerance to goal distance in meters', 'min': 0.0, 'max': 0.1, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'odom_linear_scale_correction', 'type': 'double', 'default': 1.0, 'level': 0, 'description': 'Linear correction factor', 'min': 0.0, 'max': 3.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'start_test', 'type': 'bool', 'default': False, 'level': 0, 'description': 'Check to start the test', 'min': False, 'max': True, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'bool', 'cconsttype': 'const bool'}], 'groups': [], 'srcline': 246, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'class': 'DEFAULT', 'parentclass': '', 'parentname': 'Default', 'field': 'default', 'upper': 'DEFAULT', 'lower': 'groups'}

min = {}
max = {}
defaults = {}
level = {}
type = {}
all_level = 0

#def extract_params(config):
#    params = []
#    params.extend(config['parameters'])
#    for group in config['groups']:
#        params.extend(extract_params(group))
#    return params

for param in extract_params(config_description):
    min[param['name']] = param['min']
    max[param['name']] = param['max']
    defaults[param['name']] = param['default']
    level[param['name']] = param['level']
    type[param['name']] = param['type']
    all_level = all_level | param['level']

CalibrateLinear_Y = 0
CalibrateLinear_X = 1
