from setuptools import find_packages, setup

package_name = 'node_perception_validation'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='shoukat',
    maintainer_email='shoukat@todo.todo',
    description='TODO: Package description',
    license='TODO: Package description',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': ['detection_node = node_perception_validation.detection_node:main',
        ],
    },
)
