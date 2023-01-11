FROM ubuntu:22.04

ARG USERNAME=myuser
ARG UID=1000
ARG GID=1000

RUN groupadd -g ${GID} ${USERNAME} \
    && useradd -m -u ${UID} -g ${GID} -s /bin/bash ${USERNAME}

RUN apt-get update && apt-get install -y build-essential graphicsmagick-libmagick-dev-compat

COPY . /usr/src/CIE

WORKDIR /usr/src/CIE

RUN g++ -o TEST main.cpp cie.cpp utils.cpp `Magick++-config --cxxflags --cppflags` `Magick++-config --ldflags --libs` \
    && chown ${UID}:${GID} TEST

ENV IMG_PATH=/usr/src/CIE/panda.jpeg

USER ${USERNAME}

CMD ["./TEST", "${IMG_PATH}"]
