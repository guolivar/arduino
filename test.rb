require_relative "setup"
require "test/unit"

class TestSetup < Test::Unit::TestCase
    def test_aur
        assert_equal("yaourt -S cat --noconfirm \n", aur("cat"))
        assert_equal("yaourt -S cat dog --noconfirm \n", aur("cat", "dog"))
    end

    def test_pacman
        #assert_equal('echo "Y" ' + "| sudo pacman cat \n", pacman("cat") )
        #assert_equal('echo "YY" '+ "| sudo pacman cat dog \n", pacman("cat", "dog"))
        assert_equal("pacman -S cat dog --noconfirm \n", pacman("cat", "dog"))
        assert_equal("pacman -S ctags --noconfirm \n", pacman('ctags'))
    end

    # def test_provision

    #     assert_equal('test', provision())
    # end
end