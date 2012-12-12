int main(int argc, char **argv)
{
    
	//init this
	ros::init(argc, argv, "injectPoints");

	//Set up node handle
	ros::NodeHandle n;

	//Publish an array containing 
	ros::Publisher pub = n.advertise<std_msgs::Float32MultiArray>("sonarPCarray", 100);

	ros::Subscriber sub1 = n.subscribe("sonarBearing", 100, bearingCB);
	ros::Subscriber sub2 = n.subscribe("sonarBinsArr", 100, binsArrCB);

	//set up variables to be published
	std_msgs::Float32MultiArray array;

        //set the node to loop 30 times per second.
	ros::Rate r(30);

	while (ros::ok())
	{

		//Clear array
		array.data.clear();
                //Loop for each range reading (bin) 
		for(int i = 0; i < 90; i ++)
		{
			pixelPlace(bearing, i, binsArr[i]);  //convert the current range, bearing and 
                                                             //reading to an X,Y,Z and intensity to be published to the pointcloud maker.
                                                             //explained below:

			array.data.push_back(imgx);	//x
			array.data.push_back(imgy);	//y
			array.data.push_back(0.0);	//z

			array.data.push_back(imgz);	//intensity

			//Publish array
			pub.publish(array);
		}

		//Let the world know
		ros::spinOnce();
		//Added a delay so not to spam
		r.sleep();

	}

}

