import React, { Component } from 'react';
import plyr from 'plyr';

export default class Plyr extends Component {
  componentDidMount() {
    const options = {};
    this.player = plyr.setup('#plyr-player', options);
  }
  componentWillUnmount() {
    if (this.player && this.player.length > 0) {
      for (const playerEl of this.player) {
        playerEl.destroy();
      }
    }
  }
  render() {
    const {
			poster,
			videoUrl,
		} = this.props;
    return (
		<video poster={poster} id="player" playsinline controls>
				<source src={videoUrl} type="video/mp4" />
		</video>
    );
  }
}