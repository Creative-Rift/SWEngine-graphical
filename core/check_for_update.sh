#!/bin/bash

libraries_folder="libraries"
prefix="[SWEngine-Core] "

function print() {
    echo -e $prefix ${1}
}

function download() {
        print "Download ${1}..."
        curl --request GET -sL \
             --url "http://141.94.16.86:8081/api/download/${2}?platform=${3}"\
             --output "./${libraries_folder}/${1}.tar" || exit 1
        print "Download complete"

        print "Installation ${1}..."
        cd ${libraries_folder}
        if [[ ! -d ${4} ]]; then
            mkdir ${4}
        fi
        cd ${4}
        tar -xf ../${1}.tar || exit 1
        mv *.so* ../
        rm ../${1}.tar
        cd ../../
        print "${1} installation complete"
}

if [[ ${1} == "-i" ]]; then

    if [[ ! -d ${libraries_folder} ]]; then
        mkdir ${libraries_folder} || exit 1
    fi

    download "JSONParser" "json_parser" "linux" "JSNP"
    download "Yaml" "yaml" "linux" "yaml-cpp"
fi

if [[ ${1} == "-c" ]]; then
    print "Cleaning..."
    if [[ -d ${libraries_folder} ]]; then
        rm -r ${libraries_folder} || exit 1
    fi
    if [[ -d out ]]; then
            rm -r out || exit 1
    fi
    print "Clean complete"
fi

if [[ ${1} == "-b" ]]; then
    if [[ ! -d ${libraries_folder} ]]; then
        print "$libraries_folder not found please run ./check_for_update -i before!"
        exit 1
    fi
    build_folder=build
    if [[ ! -d ${build_folder} ]]; then
        mkdir ${build_folder}
    fi
    cd $build_folder
    cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
    cmake --build .
fi

if [[ ${1} == "-debug" ]]; then
    if [[ ! -d ${libraries_folder} ]]; then
        print "$libraries_folder not found please run ./check_for_update -i before!"
        exit 1
    fi
    build_folder=build
    if [[ ! -d ${build_folder} ]]; then
        mkdir ${build_folder}
    fi
    cd $build_folder
    cmake .. -DCMAKE_BUILD_TYPE=Debug
    cmake --build .
fi

if [[ ${1} == "-h" ]]; then
    print "-h\tFor help"
    print "-i\tTo install the project"
    print "-c\tTo clear the repo"
    print "-b\tBuild your project"
    print "-b*debug\tBuild your project with debug flags"
fi

