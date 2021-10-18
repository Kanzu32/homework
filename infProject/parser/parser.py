import configparser
import json

from telethon.sync import TelegramClient
from telethon import connection

from datetime import date, datetime

# классы для работы с каналами
from telethon.tl.functions.channels import GetParticipantsRequest
from telethon.tl.types import ChannelParticipantsSearch

# класс для работы с сообщениями
from telethon.tl.functions.messages import GetHistoryRequest

# чтение конфига
config = configparser.ConfigParser()
config.read("config.ini")

api_id = config['Telegram']['api_id']
api_hash = config['Telegram']['api_hash']
username = config['Telegram']['username']

client = TelegramClient(username, api_id, api_hash)

# прокся кортежом 

#proxy = (proxy_server, proxy_port, proxy_key)

#client = TelegramClient(username, api_id, api_hash,
#    connection=connection.ConnectionTcpMTProxyRandomizedIntermediate,
#    proxy=proxy)

client.start()