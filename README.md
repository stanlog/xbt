# xbt
**XBT Tracker by Olaf van der Spek**

Automatically exported from code.google.com/p/xbt

This ReadMe is taken from http://xbtt.sourceforge.net/tracker/

## Overview
XBT Tracker is a BitTorrent tracker written in C++. It's designed to offer high performance while consuming little resources (CPU and RAM). It's a pure tracker, so it doesn't offer a frontend. You can use any (PHP) frontend you want.

XBT Tracker listens on port 2710. The announce URL is http://...:2710/announce. The debug URL is http://...:2710/debug. The scrape URL is http://...:2710/scrape. The statistics URL is http://...:2710/statistics. An experimental UDP tracker extension is also supported via announce URL udp://...:2710.

## MySQL
The tracker stores stats in a MySQL database/table. Version >= 5 is required. Create a database (xbt) and a user (xbt) with password for the tracker and use these in the next step. Create the tables defined in xbt_tracker.sql. 

## Installing under Linux
The following commands can be used to install the dependencies on Debian. The g++ version should be at least 3.4.

    apt-get install cmake g++ libboost-date-time-dev libboost-dev libboost-filesystem-dev libboost-program-options-dev libboost-regex-dev libboost-serialization-dev libmysqlclient15-dev make git zlib1g-dev

The following commands can be used to install some of the dependencies on CentOS, Fedora Core and Red Hat. The g++ version should be at least 3.4.

    yum install boost-devel gcc-c++ mysql-devel git

Enter the following commands in a terminal. Be patient while g++ is running, it'll take a few minutes.

    git clone https://github.com/stanlog/xbt.git
    cd xbt/xbt/Tracker
    ./make.sh
    cp xbt_tracker.conf.default xbt_tracker.conf

## Starting under Linux
Enter the following commands in a terminal.

    ./xbt_tracker

## Stopping under Linux
Enter the following commands in a terminal.

    killall xbt_tracker

## Configuration

The tracker reads it's configuration from the file xbt_tracker.conf and the SQL table xbt_config. There is no need to insert default values into this table.

name | default value
--- | ---
announce_interval | 1800
anonymous_connect | 1
anonymous_announce | 1
anonymous_scrape | 1
auto_register | 1
clean_up_interval | 60
daemon | 1
debug | 0
full_scrape | 0
gzip_debug | 1
gzip_scrape | 1
listen_ipa | *
listen_port | 2710
log_access | 0
log_announce | 0
log_scrape | 0
offline_message |
pid_file | xbt_tracker.pid
read_config_interval | 60
read_db_interval | 60
redirect_url |
scrape_interval | 0
table_announce_log | xbt_announce_log
table_files | xbt_files
table_files_users | xbt_files_users
table_scrape_log | xbt_scrape_log
table_users | xbt_users
write_db_interval | 15

## Auto Register

If auto_register is on, the tracker will track any torrent. If it's off, the tracker will only track torrents (identified by info_hash) that are in the xbt_files table.

    insert into xbt_files (info_hash, mtime, ctime) values ('<info_hash>', unix_timestamp(), unix_timestamp()); // insert
    update xbt_files set flags = 1 where info_hash = '<info_hash>'; // delete

## Anonymous Announce

If anonymous_announce is on, the tracker will serve any user. If it's off, the tracker will only serve users (identified by torrent_pass) that are in the xbt_users table.

The torrent_pass field in xbt_users contains the 32 char torrent_pass. The announce URL contains the same torrent_pass: /<torrent_pass>/announce

## Tables
[Table Documentation](http://visigod.com/xbt-tracker/table-documentation "Documentation to visigod.com")
