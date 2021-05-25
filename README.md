# ESP32 HTTP/s Static Site

## Configuration

Make sure `WIFI_SSID` and `WIFI_PSK` environment variables are defined

For example, you can leverage using `dotenv` by creating a `.env` file and calling it like:

```shell
dotenv make build
```

## Setup

```shell
make
```

## Development

```shell
make website_dev
make esp32_dev
```

## Build

```shell
make build
```

## Deploy to ESP32 board

```shell
make deploy
```