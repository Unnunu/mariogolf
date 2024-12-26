#!/usr/bin/env python3

def apply(config, args):
    config['baseimg'] = 'baserom.z64'
    config['myimg'] = 'build/mariogolf64.z64'
    config['mapfile'] = 'build/mariogolf64.map'
    config['source_directories'] = ['.']
    config["make_command"] = ["ninja"]
    config["objdump_flags"] = ["-M", "reg-names=32"]
    config["expected_dir"] = f"expected/"
