def site_name(site)
  site =~ /http:\/\/t.co\/\w+/
  $&
end

require 'test/unit'

class TestSongList < Test::Unit::TestCase
  def test_site_name
    site = "\"오레키 씨, 왜 허리를 뒤로 빼시는 거죠? 저 신경쓰여요!\"
             http:\/\/t.co\/MmdJqLC9Ga 호환마마 ...."
    url = site_name(site)
    assert_equal(url, "http:\/\/t.co\/MmdJqLC9Ga")
  end
end

class TestPlaylistBuilder < Test::Unit::TestCase
  def setup
    @db = DIB.connect('DBI:mysql:playlists')
  end
  def teardown
    @db.disconnect
  end
  def test_empty_playlist
    assert_equal([], @pb.playlist())
  end
end