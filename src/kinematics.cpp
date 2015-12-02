#include <ros/ros.h>
#include <kdl_parser/kdl_parser.hpp>
#include <urdf/model.h>
#include <iostream>

int main(int argc, char *argv[])
{
    KDL::Tree my_tree;
    urdf::Model my_model;

    // At least one parameter, the path to our URDF file
    if (argc == 2)
    {
        if (!my_model.initFile(argv[1])) {
            ROS_ERROR("Failed to parse urdf robot model");
            return false;
        }
        if (!kdl_parser::treeFromUrdfModel(my_model, my_tree)) {
            ROS_ERROR("Failed to construct kdl tree");
            return false;
        }

        // Print some statistics from our model
        std::cout << "URDF stats:" << std::endl;
        std::cout << "+Tree has " << my_tree.getNrOfSegments() << " link(s)" << std::endl;
        std::cout << "+Tree has " << my_tree.getNrOfJoints() << " joint(s)" << std::endl;
    }
    else
    {
        ROS_ERROR("Usage: kinematics urdf_filename");
        return false;
    }
}
