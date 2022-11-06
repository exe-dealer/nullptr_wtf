FROM alpine:3.16
RUN apk add --no-cache build-base sqlite-dev sqlite-libs
WORKDIR /tmp
COPY . ./
CMD cc program.c -lsqlite3 -o program -O2 && ./program
