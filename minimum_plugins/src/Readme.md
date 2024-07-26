The workspace contains three packages.To demonstrate and use plugins
1)polygon_base- contains the abstract class for the plugins creation(header).
2)polygon_plugins-Defines two different plugins from the polygon_base class(triangle and square).A library is created which defines both the class plugins using macros from the package pluginlib.The pluginlib macros creates the plugin but in order to be known by ros workspace we use xml format to define the name and the path.
3)use_plugin-It uses header from the polygon_base and load the plugin classes dyanamically.A simple domonstratio is through the node.No dependency in the polygon_plugins package.

In terminal-1
ros2 run use_plugin area_node