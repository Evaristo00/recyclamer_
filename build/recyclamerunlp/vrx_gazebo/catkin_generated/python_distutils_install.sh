#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/rc/recyclamer_/src/recyclamerunlp/vrx_gazebo"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/rc/recyclamer_/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/rc/recyclamer_/install/lib/python2.7/dist-packages:/home/rc/recyclamer_/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/rc/recyclamer_/build" \
    "/usr/bin/python2" \
    "/home/rc/recyclamer_/src/recyclamerunlp/vrx_gazebo/setup.py" \
     \
    build --build-base "/home/rc/recyclamer_/build/recyclamerunlp/vrx_gazebo" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/rc/recyclamer_/install" --install-scripts="/home/rc/recyclamer_/install/bin"
