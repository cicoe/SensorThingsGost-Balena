FROM balenalib/beaglebone-black-golang:latest-build AS build

# Install build tools and remove apt-cache afterwards
RUN apt-get -q update && apt-get install -yq --no-install-recommends \
    build-essential \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Build Go application
WORKDIR /go/src/github.com/balena-io-projects/app
COPY /app ./
RUN go build

# Build C application
WORKDIR /usr/src/app
COPY . /usr/src/app
RUN gcc -I./monitor -o sensorapp ./monitor/*.c

# Switch to running container
FROM balenalib/beaglebone-black-debian:stretch
COPY --from=build /usr/src/app/sensorapp sensorapp
COPY --from=build /usr/src/app/start.sh start.sh
COPY --from=build /go/src/github.com/balena-io-projects/app/ .

#switch on systemd init system in container
ENV INITSYSTEM on

# Run binary on container startup
CMD ["bash", "start.sh"]
