# -*- mode: ruby -*-
# vi: set ft=ruby :

# All Vagrant configuration is done below. The "2" in Vagrant.configure
# configures the configuration version (we support older styles for
# backwards compatibility). Please don't change it unless you know what
# you're doing.

require_relative "setup"
Vagrant.configure("2") do |config|
  # The most common configuration options are documented and commented below.
  # For a complete reference, please see the online documentation at
  # https://docs.vagrantup.com.

  # Every Vagrant development environment requires a box. You can search for
  # boxes at https://atlas.hashicorp.com/search.
  config.vm.box = "rjweyers/manjaro-i3-chromium"
  #config.vm.box = "ogarcia/archlinux"

  config.vm.provider "virtualbox" do |vb|
    # Display the VirtualBox GUI when booting the machine
  	vb.gui = true

    # using linked clone to save space and processing
	  Vagrant.require_version ">= 1.8"
    linked_clone = true
    vb.name = "SKOMOBO"

  end
  #
  # View the documentation for the provider you are using for more
  # information on available options.
  
  # Enable provisioning with a shell script. Additional provisioners such as
  # Puppet, Chef, Ansible, Salt, and Docker are also available. Please see the
  # documentation for more information about their specific syntax and use.

  config.vm.provision "shell", inline: pacman("ctags")
  config.vm.provision "shell", inline: provision(), privileged: false
  
end
