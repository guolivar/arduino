require_relative "setup"
require "test/unit"

class TestSetup < Test::Unit::TestCase
    def test_yaourt
        assert_equal("yaourt -Syu cat --noconfirm \n", yaourt("cat"))
        assert_equal("yaourt -Syu cat dog --noconfirm \n", yaourt("cat", "dog"))
    end

    def test_pacman
        assert_equal("pacman -Syu ctags --noconfirm \n", pacman('ctags'))        
        assert_equal("pacman -Syu cat dog --noconfirm \n", pacman("cat", "dog"))
    end
end