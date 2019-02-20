FROM balenalib/beaglebone-black-golang:latest-build AS build

WORKDIR /go/src/github.com/balena-io-projects/app

COPY /app ./

RUN go build

COPY --from=build /go/src/github.com/balena-io-projects/app/ .

CMD ./app
