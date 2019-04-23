FROM balenalib/beaglebone-black-golang:latest-build AS build

# Install build tools and remove apt-cache afterwards
RUN apt-get -q update && apt-get install -yq --no-install-recommends \
    build-essential \
    cmake \
    libcurl4-openssl-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Build C application
WORKDIR /usr/src/app
COPY test_sensor.c /usr/src/app
COPY . /usr/src/app

RUN mkdir /usr/src/app/build
WORKDIR /usr/src/app/build
RUN cmake ../monitor
RUN make

# Switch to operational container
FROM balenalib/beaglebone-black-debian:stretch
COPY --from=build /usr/src/app/build/monitor monitor
COPY --from=build /usr/src/app/monitor/* ./

#switch on systemd init system in container
ENV INITSYSTEM on

# Run binary on container startup
CMD ./monitor
