file(REMOVE_RECURSE
  "waypoint_markers_automoc.cpp"
  "scan_dock_scoring_plugin_automoc.cpp"
  "perception_scoring_plugin_automoc.cpp"
  "light_buoy_plugin_automoc.cpp"
  "navigation_scoring_plugin_automoc.cpp"
  "scoring_plugin_automoc.cpp"
  "stationkeeping_scoring_plugin_automoc.cpp"
  "wayfinding_scoring_plugin_automoc.cpp"
  "placard_plugin_automoc.cpp"
  "sandisland_test_automoc.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/geographic_msgs_generate_messages_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
