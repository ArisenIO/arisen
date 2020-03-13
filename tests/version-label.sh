#!/bin/bash
# The purpose of this test is to ensure that the output of the "aos --version" command matches the version string defined by our CMake files
# If the environment variable BUILDKITE_TAG is empty or unset, this test will echo success
echo '##### Aos Version Label Test #####'
if [[ "$BUILDKITE_TAG" == '' || "$BUILDKITE" != 'true' ]]; then
    echo 'This test is only run in Buildkite against tagged builds.'
    [[ "$BUILDKITE" != 'true' ]] && echo 'This is not Buildkite.'
    [[ "$BUILDKITE_TAG" == '' ]] && echo 'This is not a tagged build.'
    echo 'Exiting...'
    exit 0
fi
echo 'Tagged build detected, running test.'
# orient ourselves
[[ "$ARISEN_ROOT" == '' ]] && ARISEN_ROOT=$(echo $(pwd)/ | grep -ioe '.*/rsn/')
[[ "$ARISEN_ROOT" == '' ]] && ARISEN_ROOT=$(echo $(pwd)/ | grep -ioe '.*/ARISEN/arisen/')
[[ "$ARISEN_ROOT" == '' ]] && ARISEN_ROOT=$(echo $(pwd)/ | grep -ioe '.*/build/' | sed 's,/build/,,')
echo "Using ARISEN_ROOT=\"$ARISEN_ROOT\"."
# determine expected value
CMAKE_CACHE="$ARISEN_ROOT/build/CMakeCache.txt"
CMAKE_LISTS="$ARISEN_ROOT/CMakeLists.txt"
if [[ -f "$CMAKE_CACHE" && $(cat "$CMAKE_CACHE" | grep -c 'DOXY_RSN_VERSION') > 0 ]]; then
    echo "Parsing \"$CMAKE_CACHE\"..."
    EXPECTED="v$(cat "$CMAKE_CACHE" | grep 'DOXY_RSN_VERSION' | cut -d '=' -f 2)"
elif [[ -f "$CMAKE_LISTS" ]]; then
    echo "Parsing \"$CMAKE_LISTS\"..."
    export $(cat $CMAKE_LISTS | grep -ie 'set *( *VERSION_MAJOR' | cut -d '(' -f 2 | cut -d ')' -f 1 | awk '{print $1"="$2}')
    export $(cat $CMAKE_LISTS | grep -ie 'set *( *VERSION_MINOR' | cut -d '(' -f 2 | cut -d ')' -f 1 | awk '{print $1"="$2}')
    export $(cat $CMAKE_LISTS | grep -ie 'set *( *VERSION_PATCH' | cut -d '(' -f 2 | cut -d ')' -f 1 | awk '{print $1"="$2}')
    if [[ $(cat $CMAKE_LISTS | grep -ice 'set *( *VERSION_SUFFIX') > 0 ]]; then
        echo 'Using version suffix...'
        export $(cat $CMAKE_LISTS | grep -ie 'set *( *VERSION_SUFFIX' | cut -d '(' -f 2 | cut -d ')' -f 1 | awk '{print $1"="$2}')
        export $(echo "$(cat $CMAKE_LISTS | grep -ie 'set *( *VERSION_FULL.*VERSION_SUFFIX' | cut -d '(' -f 2 | cut -d ')' -f 1 | awk '{print $1"="$2}')" | sed "s/VERSION_MAJOR/$VERSION_MAJOR/" | sed "s/VERSION_MINOR/$VERSION_MINOR/" | sed "s/VERSION_PATCH/$VERSION_PATCH/" | sed "s/VERSION_SUFFIX/$VERSION_SUFFIX/" | tr -d '"{}$')
    else
        echo 'No version suffix found.'
        export $(echo "$(cat $CMAKE_LISTS | grep -ie 'set *( *VERSION_FULL' | grep -ive 'VERSION_SUFFIX' | cut -d '(' -f 2 | cut -d ')' -f 1 | awk '{print $1"="$2}')" | sed "s/VERSION_MAJOR/$VERSION_MAJOR/" | sed "s/VERSION_MINOR/$VERSION_MINOR/" | sed "s/VERSION_PATCH/$VERSION_PATCH/" | tr -d '"{}$')
    fi
    EXPECTED="v$VERSION_FULL"
fi
# fail if no expected value was found
if [[ "$EXPECTED" == '' ]]; then
    echo 'ERROR: Could not determine expected value for version label!'
    set +e
    echo "ARISEN_ROOT=\"$ARISEN_ROOT\""
    echo "CMAKE_CACHE=\"$CMAKE_CACHE\""
    echo "CMAKE_LISTS=\"$CMAKE_LISTS\""
    echo ''
    echo "VERSION_MAJOR=\"$VERSION_MAJOR\""
    echo "VERSION_MINOR=\"$VERSION_MINOR\""
    echo "VERSION_PATCH=\"$VERSION_PATCH\""
    echo "VERSION_SUFFIX=\"$VERSION_SUFFIX\""
    echo "VERSION_FULL=\"$VERSION_FULL\""
    echo ''
    echo '$ cat "$CMAKE_CACHE" | grep "DOXY_RSN_VERSION"'
    cat "$CMAKE_CACHE" | grep "DOXY_RSN_VERSION"
    echo '$ pwd'
    pwd
    echo '$ ls -la "$ARISEN_ROOT"'
    ls -la "$ARISEN_ROOT"
    echo '$ ls -la "$ARISEN_ROOT/build"'
    ls -la "$ARISEN_ROOT/build"
    exit 1
fi
echo "Expecting \"$EXPECTED\"..."
# get aos version
ACTUAL=$($ARISEN_ROOT/build/bin/aos --version) || : # aos currently returns -1 for --version
# test
if [[ "$EXPECTED" == "$ACTUAL" ]]; then
    echo 'Passed with \"$ACTUAL\".'
    exit 0
fi
echo 'Failed!'
echo "\"$EXPECTED\" != \"$ACTUAL\""
exit 1
