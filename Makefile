default: setup

################
# Shared tasks #
################

.PHONY: setup
setup: esp32_setup website_setup

.PHONY: build
build: website_build esp32_build

.PHONY: deploy
deploy: esp32_run

.PHONY: logs
logs: esp32_logs

###############
# ESP32 tasks #
###############

.PHONY: esp32_setup
esp32_setup:
	@pio lib install

.PHONY: esp32_build
esp32_build:
	@pio run

.PHONY: esp32_dev
esp32_dev: esp32_fs
	@pio run --target upload -t monitor

.PHONY: esp32_run
esp32_run: esp32_fs
	@pio run --target upload

.PHONY: esp32_fs
esp32_fs: website_build
	@pio run --target uploadfs

.PHONY: esp32_logs
esp32_logs:
	@pio device monitor


#################
# Website tasks #
#################

.PHONY: website_setup
website_setup:
	@cd website && npm ci

.PHONY: website_dev
website_dev:
	@cd website && npm start

.PHONY: website_build
website_build:
	@cd website && npm run build:esp32
