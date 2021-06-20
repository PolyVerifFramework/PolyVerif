from setuptools import setup

package_name = 'path_planner_validation'

setup(
    name=package_name,
    version='1.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='acclivis_linux2',
    maintainer_email='rahul.yadav@acclivistechnologies.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': ['path_planner_node = path_planner_validation.path_planner_node:main',
        ],
    },
)
