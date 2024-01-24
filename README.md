# AuthNtf

![watchers](https://img.shields.io/github/watchers/caglarkantarcioglu/authntf)
![stars](https://img.shields.io/github/stars/caglarkantarcioglu/authntf)
![forks](https://img.shields.io/github/forks/caglarkantarcioglu/authntf)
![language](https://img.shields.io/github/languages/top/caglarkantarcioglu/authntf)
![release](https://img.shields.io/github/v/release/caglarkantarcioglu/authntf)
![license](https://img.shields.io/github/license/caglarkantarcioglu/authntf)

## Description

AuthNtf is a notification service for logging and monitoring auth sessions in system.
Currently, only provides ssh sessions and uses Telegram API for notifications.

## Configuration
First you need to complete the configurations for Telegram.

`/etc/authntf/authntf.conf`
```conf
auth_log_file=/var/log/auth.log

# Telegram
telegram.token=
telegram.chat_id=
```

### Telegram Token *(telegram.token)*
Your telegram bot token for sending message (Here's a guide to [creating a new bot](https://core.telegram.org/bots/features#creating-a-new-bot))

### Telegram Chat ID *(telegram.chat_id)*
Telegram chat id that determines which chat the messages will be sent to

## Requirements

### CURL
`curl` must be installed on your system (Here you can [install curl](https://curl.se/docs/install.html))


## Installation

```bash
$ sh install.sh
```

## Usage

```bash
$ service authntf start
```

```bash
$ service authntf status
```

```bash
$ service authntf restart
```

```bash
$ service authntf stop
```