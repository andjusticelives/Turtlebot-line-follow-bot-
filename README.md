This is a modied version of the ROS Turtlebot that follows a yellow line created by Roi Yehoshua.
What has been changed is the CMAKELists.txt file.
For some reason when I ran his code it wouldnt work on my machine and produced nothing but errors.
After edditing the CMAKELists.txt file to get the opencv directories everything is running fine now.
You can check out the original at  http://u.cs.biu.ac.il/~yehoshr1/89-685/ look for the follow bot package in lecture 10.
Now to run this package you will need a few things.
First you will need to have ROS Kinetic installed.
ROS kinetic  can only be installed in you have ubunto 16.
Then you will need to have Turtlebot installed.
To install Turtlebot open up terminal and type in 
$ sudo apt-get install ros-indigo-turtlebot-gazebo ros-indigo-turtlebot-apps ross-indigo-turtlebot-rviz-launchers 
If you dont have turtlebot installed it wont run.
Take the repository and store it into you catkin/src/ folder.
To run the simulation open up the terminal. enter in      
$ cd ~/catkin_ws/              
then 
$ catkin_make    
after that runs you enter   
$ source devel/setup.bash  
and lastly to run the simulation you type into the terminal 
$ roslaunch follow_bot course.launch                     
Now if you dont have your catkin set up what you need to do is open up your ubunto terminal(a new one). 
And type in 
$ mkdir catkin_ws      
$ cd catkin_ws        
$  catkin_make        
To clone the files in into the source repository you can enter these commands into the terminal.  
$ cd ~/catkin_ws/src   
$ git clone https://github.com/andjusticelives/Turtlebot-line-follow-bot-.git      
$ cd ..      
$ catkin_make   
