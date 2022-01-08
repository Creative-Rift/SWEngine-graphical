#!/usr/bin/bash

function download() {
        echo -e "Download ${1}..."
        curl --request GET -sL \
             --url "http://141.94.16.86:8081/api/download/${2}"\
             --output "./libs/${1}.tar"
        echo -e "Download complete"

        echo -e "Installation ${1}..."
        cd libs
        tar -xf ${1}.tar
        rm ${1}.tar
        cd ..
        echo -e "Installation complete"
}

if [[ ! -d "libs" ]]; then
    mkdir libs
fi

if [[ ${1} == "-i" ]]; then

    download "SWEngine-Core" "core"
    download "JSONParser" "jsonparser"
    download "Glfw" "openglmodule?file=glfw"

fi

