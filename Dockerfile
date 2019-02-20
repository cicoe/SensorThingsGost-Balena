FROM balenalib/beaglebone-black-golang:latest-build AS build

# Install build tools and remove layer cache afterwards
RUN apt-get -q update && apt-get install -yq --no-install-recommends \
	build-essential cmake\
	&& apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /go/src/github.com/balena-io-projects/app
#COPY /app ./
#CMD ["run.sh"]

COPY /app ./

RUN go build

#FROM balenalib/%%BALENA_MACHINE_NAME%%-debian:stretch

COPY --from=build /go/src/github.com/balena-io-projects/app/ .

CMD ./app
